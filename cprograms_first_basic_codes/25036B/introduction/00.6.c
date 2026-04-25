#include <stdio.h>

int main()
{
    int num1, num2;

    printf("Enter the numbers: ");
    scanf("%d%d", &num1, &num2);

    int sum = num1 + num2;

    printf("Sum is %d\n", sum);

    return 0;
}