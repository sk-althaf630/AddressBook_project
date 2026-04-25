#include <stdio.h>
int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    int maske = 1;
    printf("RES: ---> %d\n", num|maske);
}