#include <stdio.h>
int main()
{
    int num = 10;
    static *ptr;
    ptr = &num;

    printf("%d\n", *ptr);
}