#include <stdio.h>
int main()
{
    int num = 10;
    static int * ptr;
    ptr = &num;

    printf("*ptr= --> %d\n", *ptr);
    return 0;
}