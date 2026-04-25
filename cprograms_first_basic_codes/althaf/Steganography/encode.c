#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "types.h"
#include "common.h"
#include <unistd.h>

/* Function Definitions */

/* Get image size
 * Input: Image file ptr
 * Output: width * height * bytes per pixel (3 in our case)
 * Description: In BMP Image, width is stored in offset 18,
 * and height after that. size is 4 bytes
 */

Status read_and_validate_encode_args(char *argv[], EncodeInfo *encInfo)
{
    //argv[2] -> .bmp -> store argv[2] in structure encInfo->src_image_fname = argv[2];

    char *check_bmp = strstr(argv[2],".bmp");
    if(check_bmp == NULL)
    {
        printf("Invalid source file\n");
        return e_failure;
    }
    else
    {
        strcpy(encInfo -> src_image_fname,argv[2]);
    }

    //argv[3] -> .txt -> encInfo->secret_fname = argv[3] -> strcpy(encInfo->extn_secret_file, strstr(argv[3], "."))

    char *scr_file = strstr(argv[3],".txt");

    if(scr_file == NULL)
    {
        printf("Invalid secret file\n");
        return e_failure;
    }

    strcpy(encInfo -> extn_secret_file,scr_file);
    strcpy(encInfo->secret_fname, argv[3]);

    //argv[4] -> NULL-> store "stego.bmp" in structure
        //   -> no NULL -> .bmp -> store argv[4] in structure

    if(argv[4] == NULL)
        strcpy(encInfo -> stego_image_fname,"stego.bmp");
    else
        strcpy(encInfo -> stego_image_fname,argv[4]);

    return e_success;
}

uint get_image_size_for_bmp(FILE *fptr_image)
{
    uint width, height;
    // Seek to 18th byte
    fseek(fptr_image, 18, SEEK_SET);

    // Read the width (an int)
    fread(&width, sizeof(int), 1, fptr_image);
    //printf("width = %u\n", width);

    // Read the height (an int)
    fread(&height, sizeof(int), 1, fptr_image);
    //printf("height = %u\n", height);

    // Return image capacity
    return width * height * 3;
}

/* 
 * Get File pointers for i/p and o/p files
 * Inputs: Src Image file, Secret file and
 * Stego Image file
 * Output: FILE pointer for above files
 * Return Value: e_success or e_failure, on file errors
 */
Status open_files(EncodeInfo *encInfo)
{
    // Src Image file
    encInfo->fptr_src_image = fopen(encInfo->src_image_fname, "r");
    // Do Error handling
    if (encInfo->fptr_src_image == NULL)
    {
    	//perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->src_image_fname);

    	return e_failure;
    }

    // Secret file
    encInfo->fptr_secret = fopen(encInfo->secret_fname, "r");
    // Do Error handling
    if (encInfo->fptr_secret == NULL)
    {
    	//perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->secret_fname);

    	return e_failure;
    }

    // Stego Image file
    encInfo->fptr_stego_image = fopen(encInfo->stego_image_fname, "w");
    // Do Error handling
    if (encInfo->fptr_stego_image == NULL)
    {
    	//perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->stego_image_fname);

    	return e_failure;
    }

    // No failure return e_success
    return e_success;
}

uint get_file_size(FILE *fptr)
{
    fseek(fptr, 0,SEEK_END);
    long size = ftell(fptr);
    fseek(fptr, SEEK_CUR, SEEK_SET);
    return size;
}

Status check_capacity(EncodeInfo *encInfo)
{
    encInfo->image_capacity = get_image_size_for_bmp(encInfo->fptr_src_image);

    encInfo->size_secret_file = get_file_size(encInfo->fptr_secret);

    if((encInfo->image_capacity-54) > (strlen(MAGIC_STRING) + sizeof(int) + strlen(encInfo->extn_secret_file) + sizeof(int) + encInfo->size_secret_file )*8)
        return e_success;
    else
        return e_failure;
}

Status encode_data_to_image(char *data, int size, FILE *fptr_src_image, FILE *fptr_stego_image)
{
    char arr[8]; 

    for(int i = 0; i < size; i++)
    {
        fread(arr, 8, 1, fptr_src_image);
        encode_byte_to_lsb(data[i], arr);
        fwrite(arr, 8, 1, fptr_stego_image);
    }

    return e_success;
}

Status encode_magic_string(const char *magic_string, EncodeInfo *encInfo)
{
    // encode_data_to_image(MAGIC_STRING, strlen(MAGIC_STRING), encInfo->fptr_src_image, encInfo->fptr_stego_image);

    encode_data_to_image(MAGIC_STRING,strlen(MAGIC_STRING),encInfo -> fptr_src_image, encInfo -> fptr_stego_image);
    return e_success;
}

Status do_encoding(EncodeInfo *encInfo)
{
    // open_files() == e_failure -> error -> return e_failure

    if (open_files(encInfo) == e_failure)
        return e_failure;

    //check_capacity() == e_failure -> error -> return e_failure

    if (check_capacity(encInfo) == e_failure)
        {
            printf("Secret file size is too large\n");
            return e_failure;
        }

    //copy_bmp_header() == e_failure -> error -> return e_failure
    rewind(encInfo -> fptr_src_image);
    rewind(encInfo -> fptr_secret);
    if((copy_bmp_header(encInfo -> fptr_src_image, encInfo -> fptr_stego_image)) == e_failure)
        return e_failure;

    //encode_magic_string() == e_failure -> error -> return e_failure

    if((encode_magic_string(MAGIC_STRING,encInfo)) == e_failure)
        return e_failure;
    
    encInfo -> size_secret_file_extn = strlen(encInfo -> extn_secret_file);

    if((encode_secret_file_size(encInfo -> size_secret_file_extn, encInfo)) == e_failure)
        return e_failure;

    if((encode_secret_file_extn(encInfo -> extn_secret_file, encInfo)) == e_failure)
        return e_failure;

    encInfo -> size_secret_file = get_file_size(encInfo -> fptr_secret);
    rewind(encInfo -> fptr_secret);

    if((encode_secret_file_size(encInfo -> size_secret_file, encInfo)) == e_failure)
        return e_failure;

    fread(encInfo -> secret_data,encInfo -> size_secret_file,1,encInfo ->  fptr_secret);
    if((encode_data_to_image(encInfo -> secret_data,encInfo -> size_secret_file, encInfo -> fptr_src_image, encInfo -> fptr_stego_image)) == e_failure)
        return e_failure;

    if((copy_remaining_img_data(encInfo -> fptr_src_image, encInfo -> fptr_stego_image)) == e_failure)
        return e_failure;
    
    for(int i = 0; i <= 100; i++)
    {
        printf("Encoding..%d%%\r",i);
        fflush(stdout);
        usleep(50000);
    }
    printf("\rEncoded Successfully..\n");
}

Status copy_bmp_header(FILE *fptr_src_image, FILE *fptr_dest_image)
{
    char header[60];

    fread(header,54,1,fptr_src_image);
    fwrite(header,54,1,fptr_dest_image);
    return e_success;
}

Status encode_byte_to_lsb(char data, char *image_buffer)
{
    for(int i = 0; i < 8; i++)
    {
        image_buffer[i] = (image_buffer[i] & (~1));
        char get = (data >> i) & 1;
        image_buffer[i] = image_buffer[i] | get;
    }
    return e_success;
}

Status encode_secret_file_size(long file_size, EncodeInfo *encInfo)
{
    char arr[32]; 

    fread(arr, 32, 1, encInfo -> fptr_src_image);
    encode_integer_to_lsb(file_size, arr);
    fwrite(arr, 32, 1, encInfo -> fptr_stego_image);

    return e_success;
}

Status encode_integer_to_lsb(long file_size, char *arr)
{
    for(int i = 0; i < 32; i++)
    {
        arr[i] = arr[i] & (~1);
        int get = (file_size >> i) & 1;
        arr[i] = arr[i] | get;
    }

    return e_success;
}

Status encode_secret_file_extn(const char *file_extn, EncodeInfo *encInfo)
{
    int size = strlen(file_extn);
    char arr[8]; 

    for(int i = 0; i < size; i++)
    {
        fread(arr, 8, 1, encInfo -> fptr_src_image);
        encode_byte_to_lsb(file_extn[i], arr);
        fwrite(arr, 8, 1, encInfo -> fptr_stego_image);
    }

    return e_success;
}


Status copy_remaining_img_data(FILE *fptr_src, FILE *fptr_dest)
{
    char ch;

    while((fread(&ch,1,1,fptr_src)) == 1)
    {
        fwrite(&ch,1,1,fptr_dest);
    }
}