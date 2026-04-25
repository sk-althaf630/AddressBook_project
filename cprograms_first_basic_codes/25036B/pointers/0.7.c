#include <stdio.h>
int main()
{
    int num = 123;

    int *iptr = &num;
    int *cptr = &num;
    int *dptr = &num;

    printf("iptr is --> %u\n", iptr);
    printf("iptr is --> %u\n", iptr +2);
    printf("cptr is --> %u\n", cptr);
    printf("cptr is --> %u\n", cptr + 3);
    printf("dptr is --> %u\n", dptr);
    printf("dptr is --> %u\n", dptr + 5);

}