/*
Name: Shaik.Althaf
Project: LSB-based image steganography
Submission Date: 25/02/2026
Description:--
This project implements Least Significant Bit (LSB) Image Steganography using the C programming 
language. Steganography is the art of hiding information within digital media, andthe LSB technique 
embeds secret data into the least significant bits of image pixels, ensuring minimal visual distortion. 
The system provides functionality to encode hidden messages into an image and later decode them for 
retrieval. It demonstrates practical applications of bitwise operations, file handling, and low‑level 
data manipulation, making it a valuable project in both information security and embedded programming 
concepts.
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "encode.h"
#include "types.h"
#include "decode.h"

OperationType check_operation_type(char *argv[])
{
    if(strcmp(argv[1],"-e") == 0)
    {
        return e_encode;
    }
    else if(strcmp(argv[1], "-d") == 0)
    {
        return e_decode;
    }
    else
    {
        return e_unsupported;
    }
    
}

int main(int argc, char *argv[])
{
    if(argc < 3)  
    {
        printf("ERROP : You have given worring arguments...\n");
        return e_failure;
    }

    OperationType res = check_operation_type(argv);

   switch(res)
   {
        case e_encode:
        {
         EncodeInfo stu;
            if(argc <= 3)  
            {
                printf("ERROP : Encodeing arguments shulde be greater then 3...\n");
                return e_failure;
            }


            if(read_and_validate_encode_args(argv, &stu) == e_success)
            {
                do_encoding(&stu);

                fclose(stu.fptr_src_image);
                fclose(stu.fptr_secret);
                fclose(stu.fptr_stego_image);

                for(int i = 0; i <= 100; i++)
                {
                    printf("Encoding..%d%%\r",i);
                    fflush(stdout);
                    usleep(50000);
                }
                printf("\rEncoded Success!..\n");
            }
            else
            {
                printf("Invalid encode arguments\n");
            }
            break;
        }

       case e_decode:
       {
            DecodeInfo stu1;
            if(read_and_validate_decode_args(argv, &stu1) == e_success)
            {
                do_decoding(&stu1);

                fclose(stu1.fptr_stego_image);
                fclose(stu1.fptr_output);


                for(int i = 0; i <= 100; i++)
                {
                    printf("Dncoding..%d%%\r",i);
                    fflush(stdout);
                    usleep(50000);
                }
                printf("\rDecoded Success!..\n");

            }
            else
            {
                printf("Invalid decode arguments\n");
            }
            break;
        }

        default:
            printf("Unsupported operation. Use -e for encode of -d for decode.\n");
            break;
   }
    return 0;
}
