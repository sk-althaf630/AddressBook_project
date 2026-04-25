#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "encode.h"
#include "types.h"
#include "common.h"

/* Function Definitions */

/* Get image size
 * Input: Image file ptr
 * Output: width * height * bytes per pixel (3 in our case)
 * Description: In BMP Image, width is stored in offset 18,
 * and height after that. size is 4 bytes
 */
/* Validate and store arguments */
Status read_and_validate_encode_args(char *argv[], EncodeInfo *encInfo)
{

    //step 1:- assigning the source file name to EncodeInfo structure and checking ".bmp".
    char *check_bmp = strstr(argv[2],".bmp");
    if(check_bmp == NULL)
    {
        printf("Error : Invalid source file\n");
        return e_failure;
    }
    else
    {
        encInfo->src_image_fname = argv[2];
    }

    //step 2:- assigning the secret file name to EncodeInfo structure and checking ".".
    encInfo->secret_fname = argv[3];
    char *extn = strstr(argv[3], ".");
    if(extn == NULL)
    {
        printf("Error : Invalid secret file\n");
        return e_failure;
    }

    //step 3:- Extracting extn form the secret file and assigning that to  extn_secret_file string
    strcpy(encInfo->extn_secret_file, extn);

    //step 4:- Handle output file name
    if(argv[4] == NULL)
    {
        encInfo->stego_image_fname = "stego.bmp";
    }
    else
    {
        if(strstr(argv[4], ".bmp") == NULL)
        {
            printf("Error : Invalid output file. Must be a .bmp file\n");
            return e_failure;
        }
        encInfo->stego_image_fname = argv[4];
    }

    return e_success;
}

/* Get BMP image size */
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

/* Open files safely */
Status open_files_encode(EncodeInfo *encInfo)
{
    // Src Image file
    encInfo->fptr_src_image = fopen(encInfo->src_image_fname, "rb");
    // Do Error handling
    if (encInfo->fptr_src_image == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->src_image_fname);

    	return e_failure;
    }

    // Secret file
    encInfo->fptr_secret = fopen(encInfo->secret_fname, "r");
    // Do Error handling
    if (encInfo->fptr_secret == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->secret_fname);

    	return e_failure;
    }

    // Stego Image file
    encInfo->fptr_stego_image = fopen(encInfo->stego_image_fname, "wb");
    // Do Error handling
    if (encInfo->fptr_stego_image == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->stego_image_fname);

    	return e_failure;
    }

    // No failure return e_success
    return e_success;
}

/* Get file size */
uint get_file_size(FILE *fptr)
{
    fseek(fptr, 0,SEEK_END);

    return ftell(fptr);
}

/* Check encoding capacity */
Status check_capacity(EncodeInfo *encInfo)
{
    encInfo->image_capacity = get_image_size_for_bmp(encInfo->fptr_src_image);

    encInfo->size_secret_file = get_file_size(encInfo->fptr_secret);

    if((encInfo->image_capacity-54) > (strlen(MAGIC_STRING) + sizeof(int) + strlen(encInfo->extn_secret_file) + sizeof(int) + encInfo->size_secret_file )*8)
    {
        return e_success;
    }
    else
    {
        return e_failure;
    }
}

/* Encode a byte into LSBs */
Status encode_byte_to_lsb(char data, char *image_buffer)
{
    for(int i = 0; i < 8; i++)
    {
        //clearing part
        image_buffer[i] = (image_buffer[i] &(~1));
        //geting part
        char get = (data >> i) & 1;
        //setting part
        image_buffer[i] = image_buffer[i] | get;
    }

    return e_success;
}

/* Encode integer into LSBs*/
Status encode_integer_to_lsb(long file_size, char *image_buffer)
{
    for(int i = 0; i < 32; i++)
    {
        image_buffer[i] = (image_buffer[i] &~1);
        char get = (file_size >> i) & 1;
        image_buffer[i] = image_buffer[i] | get;
    }

    return e_success;
}

/* Encode data string into image */
Status encode_data_to_image(const char *data, int size, FILE *fptr_src_image, FILE *fptr_stego_image)
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

/* Copy BMP header */
Status copy_bmp_header(FILE *fptr_src_image, FILE *fptr_dest_image)
{
    char arr[54];
    
    fread(arr,54,1,fptr_src_image);
    fwrite(arr,54,1,fptr_dest_image);

    return e_success;
}

/* Encode magic string */
Status encode_magic_string(const char *magic_string, EncodeInfo *encInfo)
{
    
    return encode_data_to_image(MAGIC_STRING, strlen(MAGIC_STRING), encInfo->fptr_src_image, encInfo->fptr_stego_image);
}

/* Encode secret file extension size */
Status encode_secret_file_extn_size(const char *file_extn, EncodeInfo *encInfo)
{
    char arr[32];

    int size = strlen(file_extn);
    fread(arr,32,1, encInfo->fptr_src_image);
    encode_integer_to_lsb(size,arr);
    fwrite(arr,32,1,encInfo->fptr_stego_image);

    return  e_success;
}

/* Encode secret file extension */
Status encode_secret_file_extn(const char *file_extn, EncodeInfo *encInfo)
{
    return encode_data_to_image(file_extn, strlen(file_extn), encInfo->fptr_src_image, encInfo->fptr_stego_image);
}

/* Encode secret file size */
Status encode_secret_file_size(long file_size, EncodeInfo *encInfo)
{
    char arr[32];

    fread(arr,32,1, encInfo->fptr_src_image);
    encode_integer_to_lsb(file_size,arr);
    fwrite(arr,32,1,encInfo->fptr_stego_image);

    return e_success;
}

/* Encode secret file data */
Status encode_secret_file_data(EncodeInfo *encInfo)
{
    rewind(encInfo->fptr_secret);
    char *data_str = malloc(encInfo->size_secret_file);
    if(!data_str)
    {
        printf("ERROR : Memory allocation failed\n");
        return e_failure;
    }

    fread(data_str, encInfo->size_secret_file, 1, encInfo->fptr_secret);
    encode_data_to_image(data_str,encInfo->size_secret_file, encInfo->fptr_src_image, encInfo->fptr_stego_image);

    free(data_str);
    return e_success;
}

/* Copy remaining image data */
Status copy_remaining_img_data(FILE *fptr_src, FILE *fptr_dest)
{
    char remaining_info;
    while(fread(&remaining_info, 1,1,fptr_src) == 1)
    {
        fwrite(&remaining_info,1,1,fptr_dest);
    }

    return e_success;
}

/* Full encoding pipeling */
Status do_encoding(EncodeInfo *encInfo)
{
    //step 1:- Do error handling on file opening stage.
    if(open_files_encode(encInfo) == e_failure)
    {
        printf("ERROR : Unable to opening the files\n");

        return e_failure;
    }

    //step 2 :- Do error handling on file capacity for sorce and seceret files
    if(check_capacity(encInfo) == e_failure)
    {
        printf("ERROR : Insufficint image capacity\n");
        return e_failure;
    }


    //step 3:- rewind the two files, the file pointers shude point to bigining and Do error handling.
    rewind(encInfo -> fptr_src_image);
    if(copy_bmp_header(encInfo->fptr_src_image, encInfo->fptr_stego_image) == e_failure)
    {
        printf("ERROR : Copying is failued\n");
        return e_failure;
    }

    //step 4:- Encode magic string in to stego.bmp
    if(encode_magic_string(MAGIC_STRING,encInfo) == e_failure)
    {
        printf("ERROR : Encodeing is failued\n");
        return e_failure;
    }

    //step 5:- Encode secret file extention size
   if(encode_secret_file_extn_size(encInfo->extn_secret_file,encInfo) == e_failure)
    {
        printf("ERROR : Finding the secret file extention size as failued\n");
        return e_failure;
    }

    //step 6:- Encode the secret file extan in stego.bmp
    if(encode_secret_file_extn(encInfo->extn_secret_file,encInfo) == e_failure)
    {
        printf("ERROR :  Encodeing secret file extension is failued\n");
        return e_failure;
    }

    //step 7:- Encode the size of the secret file in stego.bmp
    if(encode_secret_file_size(encInfo->size_secret_file,encInfo) == e_failure)
    {
        printf("ERROR : Encodeing secret file size is failued\n");
        return e_failure;
    }

    //step 8:- Encode the secret file data in image.
    if(encode_secret_file_data(encInfo) == e_failure)
    {
        printf("ERROR : Encodeing secret file data is failued\n");
        return e_failure;
    }

    //step 9:- Encode the remaining info to stego file.
    if(copy_remaining_img_data(encInfo->fptr_src_image,encInfo->fptr_stego_image) == e_failure)
    {
        printf("ERROR : Copying remaining image data is failued\n");
        return e_failure;
    }


    return e_success;
}