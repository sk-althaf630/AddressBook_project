/*Check number is 2’s power or not.*/
#include <stdio.h>
int main()
{
    int num;
    printf("Enter the number : ");
    scanf("%d", &num);

    if(num > 0 && (num & (num - 1)) == 0)
    {
        printf("The number %d is a power of 2\n", num);
    }
    else
    {
        printf("The number %d is NOT a power of 2\n", num);
    }

    return 0;
}