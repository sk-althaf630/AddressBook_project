#include <stdio.h>
int main()
{
    unsigned int num = 0x12345678;
    char * cptr = (char*)&num;
    if(*cptr == 0x78)
    {
    printf("Little endinan%d\n", *cptr);
    }
    else
    {
    printf("Big endinan%d\n", *cptr);
    }
}