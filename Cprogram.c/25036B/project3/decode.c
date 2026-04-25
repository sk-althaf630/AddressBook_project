#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decode.h"
#include "types.h"
#include "common.h"

/* Function Definitions */

/* Validateing the stored argumenst */
Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo)
{
    //step 1:- assign the source file name to structure and checking .bmp extention also.
    decInfo->stego_image_fname = argv[2];
    if(strstr(decInfo->stego_image_fname, ".bmp") == NULL)
    {
        return e_failure;
    }

    //step 2:- assigning the default name and if  given means removeing extention.
    if(argv[3] == NULL)
    {
        strcpy(decInfo->output_fname ,"decoded_output");
    }
    else
    {
        strcpy(decInfo->output_fname, argv[3]);
        //Finding the address of "." storing in that NULL
        char *pos = strchr(decInfo->output_fname, '.');
        //Error handaling.
        if(pos != NULL)
        {
          *pos = '\0';
        }
    }

    return e_success;
}

/* OPen files safely */
Status open_files(DecodeInfo *decInfo)
{
    
    decInfo->fptr_stego_image = fopen(decInfo->stego_image_fname, "rb");
    if(decInfo->fptr_stego_image == NULL)
    {
        perror("fopen");
        fprintf(stderr, "ERROR : Unable to open file %s\n", decInfo->stego_image_fname);
        return e_failure;
    }

    return e_success;
}

/* skip BMP header */
Status skip_bmp_header(FILE *fptr_stego_image)
{

    if(fseek(fptr_stego_image, 54, SEEK_SET) != 0)
    {
        return e_failure;
    }

    return e_success;
    

}

/* Decode a byte from LSBs */
char decode_byte_form_lsb(const char *image_buffer)
{
    char data = 0;
    for(int i = 0; i < 8; i++)
    {
        data |= ((image_buffer[i] & 1) << i);
    }
    return data;
}

/* Decode data magic_string from image and compare */
Status decode_string_lsb(FILE *fptr_stego_image)
{
    char magic_string[3];
    if(decode_data_form_image(magic_string, 2, fptr_stego_image) == e_failure)
    {
        return e_failure;
    }
    magic_string[2] = '\0';

    if(strcmp(magic_string,MAGIC_STRING) != 0)
    {
        printf("ERROR : Magic string mismatch. Not a valid stego image.\n");
        return e_failure;
    }

    return e_success;
}


/* Decode magic string */
Status decode_magic_string(const char *magic_string, DecodeInfo *decInfo)
{
    if(decode_string_lsb(decInfo ->fptr_stego_image) == e_failure)
    {
        return e_failure;
    }
   
    return e_success;
}

/* Decode integer from LSBs */
int decode_integer_from_lsb(char *image_buffer)
{
    int data = 0;
    for(int i = 0; i < 32; i++)
    {
        data |= ((image_buffer[i] & 1) << i);
    }

    return data;
}


/* Decode secreat file extension */
Status decode_file_extn_size(DecodeInfo *decInfo)
{
    char arr[32];

    fread(arr, 32,1, decInfo->fptr_stego_image);
    decInfo->extn_size = decode_integer_from_lsb(arr);

    return e_success;
}

/* Decode data from image form pixle */
Status decode_data_form_image(char *data, int size, FILE *fptr_stego_image)
{
    char arr[8];
    for(int i = 0; i < size; i++)
    {
        if(fread(arr, 8, 1, fptr_stego_image) != 1)
        {
            return e_failure;
        }
        data[i] = decode_byte_form_lsb(arr);
    }
    
    return e_success;
}

/* Decode secret file extendion */
Status decode_secret_file_extn(DecodeInfo *decInfo)
{
    decode_data_form_image(decInfo->extn_secret_file,decInfo->extn_size,
                            decInfo->fptr_stego_image);

    return e_success;
}

Status open_secret_file(DecodeInfo *decInfo)
{
    decInfo -> fptr_output = fopen(decInfo-> output_fname,"wb");

    if(decInfo->fptr_output == NULL)
    {
        return e_failure;
    }

    return e_success;
}



/*Decode secret file size */
Status decode_secret_file_size(DecodeInfo *decInfo)
{
    char arr[32];

    //Get secret file size
    if(fread(arr, 32, 1, decInfo->fptr_stego_image) !=1)
    {
        return e_failure;
    }
    decInfo->size_secret_file = decode_integer_from_lsb(arr);


    return e_success;
}

/* Decode secret file data */
Status decode_secret_file_data(DecodeInfo *decInfo)
{

    //Allocate and read data.
    char *data_str = malloc(decInfo->size_secret_file);
    if(!data_str)
    {
        printf("ERROR : Memory allocation failed\n");
        return e_failure;
    }

    if(decode_data_form_image(data_str, decInfo->size_secret_file, decInfo->fptr_stego_image) == e_failure)
    {
        free(data_str);
        return e_failure;
    }

    //writing to file
    if(fwrite(data_str, decInfo->size_secret_file, 1, decInfo->fptr_output) != 1)
    {
        return e_failure;
    }
    free(data_str);
    return e_success;
}

/* Main decoding pipeling */
Status do_decoding(DecodeInfo *decInfo)
{
    if(open_files(decInfo) == e_failure)
    {
        printf("ERROR : Unable to opening the files\n");
        return e_failure;
    }

    if(skip_bmp_header(decInfo->fptr_stego_image) == e_failure)
    {
        return e_failure;
    }

    if(decode_magic_string(MAGIC_STRING, decInfo) == e_failure)
    {
        return e_failure;
    }

    if(decode_file_extn_size(decInfo) == e_failure)
    {
        return e_failure;
    }

    if(decode_secret_file_extn(decInfo) == e_failure)
    {
        return e_failure;
    }

    strcat(decInfo -> output_fname,decInfo -> extn_secret_file);

    if((open_secret_file(decInfo)) == e_failure)
    {
        printf("secret file failued to open\n");
        return e_failure;
    }

    if(decode_secret_file_size(decInfo) == e_failure)
    {
        return e_failure;
    }

    if(decode_secret_file_data(decInfo) == e_failure)
    {
        return e_failure;
    }

    return e_success;
}


