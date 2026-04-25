#include <stdio.h>
int main()
{
    char * cptr;
    int * nptr;
    float *fptr;
    double * dptr;

    printf("size of cptr --> %c\n", sizeof(cptr));
    printf("size of cptr --> %d\n", sizeof(nptr));
    printf("size of cptr --> %f\n", sizeof(fptr));
    printf("size of cptr --> %lf\n", sizeof(dptr));

    return 0;
}