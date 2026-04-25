#include <stdio.h>

int main()
{
    int num1, num2;

    printf("Enter the number: ");
    scanf("%d%d", &num1, &num2);

    if (num1 > num2)

        printf("num1 is larger\n");
    else if (num2 > num1)
    {
        printf("num2 is smaller\n");
    }
    else{
        printf("both are equal\n");
    }
        
    return 0;
}