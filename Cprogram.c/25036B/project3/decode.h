#ifndef DECODE_H
#define DECODE_H

#include "types.h"

typedef struct
{
    /* Stego file info */
   char *stego_image_fname;
   FILE *fptr_stego_image;

   /*output file info */
   char output_fname[30];
   FILE *fptr_output;

   /* secret file extension */
   char extn_secret_file[10]; //ecough for ".txt", ".bmp", ".mp3", etc.
   int extn_size;


   /* secret file size */
   long size_secret_file;

}DecodeInfo;

/* Fuction prototypes */

/* Read and validate decode args from argv */
Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo);
/* OPening sorce files safely */
Status open_files(DecodeInfo *decInfo);
/* skip BMP header */
Status skip_bmp_header(FILE *fptr_stego_image);



/* Decode a byte from LSBs */
char decode_byte_form_lsb(const char *image_buffer);
/* Decode integer from LSBs */
int decode_integer_from_lsb(char *image_buffer);

/* Decode data from image form pixle */
Status decode_data_form_image(char *data, int size, FILE *fptr_stego_image);


/* Decode magic string */
Status decode_magic_string(const char *magic_string, DecodeInfo *decInfo);
/* Decode magic string */
Status decode_string_lsb(FILE *fptr_stego_image);
/* Decode secreat file extension */
Status decode_file_extn_size(DecodeInfo *decInfo);
/* Decode secret file extendion */
Status decode_file_extn_size(DecodeInfo *decInfo);
/*Decode secret file size */
Status decode_secret_file_extn(DecodeInfo *decInfo);
/* Decode secret file data */
Status decode_secret_file_data(DecodeInfo *decInfo);
/* Perform the decoding */
Status do_decoding(DecodeInfo *encInfo);
/* opening output file safely */
Status open_secret_file(DecodeInfo *decInfo);

#endif
