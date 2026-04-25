#include <stdio.h>

int main()
{
    int num1, num2;

    printf("Enter the number: ");
    scanf("%d%d", &num1, &num2);

    if (num1 > num2)

        printf("num1 is larger\n");
    else 
    {
        printf("num2 is smaller\n");
    }
        
    return 0;
}