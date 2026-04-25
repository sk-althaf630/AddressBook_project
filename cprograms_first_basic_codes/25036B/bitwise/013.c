#include <stdio.h>
int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%x", &num);
    int maske = 1;
    printf("RES: ---> %x\n", num^maske);
}