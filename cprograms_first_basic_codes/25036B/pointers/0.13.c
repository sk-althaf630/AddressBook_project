#include<stdio.h>
int main()
{
    double d=7.2;
    void *ptr=&d;
    printf("%hhx\n", *(char *)ptr);
    printf("%hx\n", *(short *)ptr);
    printf("%x\n", *(int *)ptr);
    printf("%x\n", *(int *)(ptr+4));
    printf("%hx\n", *(short *)(ptr+3));
    printf("%hhx\n", *(char *)(ptr+7));
}