#ifndef DECODE_H
#define DECODE_H

typedef struct _DecodeInfo
{
    char secret_text_fname[20];
    FILE *fptr_stego_bmp;
    FILE *fptr_secret_data;


} DecodeInfo;

/* Read and validate Decode args from argv */
Status read_and_validate_decode_args(char *argv[], DecodeInfo *encInfo);

/* Perform the decoding */
Status do_decoding(DecodeInfo *encInfo);

/* Get File pointers for i/p and o/p files */
Status open_decode_files(DecodeInfo *encInfo);

/* Skip bmp image header */
Status skip_bmp_header(FILE *fptr_stego_bmp);

/* Decode Magic String */
Status decode_magic_string(EncodeInfo *encInfo);

#endif