//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "encode.h"
#include "types.h"

OperationType check_operation_type(char *argv[])
{
    if((strcmp(argv[1],"-e")) == 0)
        return e_encode;
    else if((strcmp(argv[1],"-d")) == 0)
        return e_decode;
    else
        return e_unsupported;
}

int main(int argc, char *argv[])
{
    if(argc < 4)
    {
        printf("So give the arguments as below\n");
        printf("./a.out -e <input.bmp> <secret.txt> [output.bmp]\n");
        return e_failure;
    }

    EncodeInfo encInfo; // structure decleration

    //res = check_operationType(argv);
    int res = check_operation_type(argv);

    //res -> e_encode -> read_and_validate_encodde_arg(); -> do_encoding();

    if(res == e_encode)
    {
       if (read_and_validate_encode_args(argv, &encInfo) == e_success)
            do_encoding(&encInfo);
        else
            return e_failure;

        fclose(encInfo.fptr_src_image);
        fclose(encInfo.fptr_secret);
        fclose(encInfo.fptr_stego_image);
    }

    //res -> e_decode -> read_and_validate_decode_arg();  -> do_decoding();

    //res -> e_usupported -> error -> terminate
    return 0;
}
