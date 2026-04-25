#include <stdio.h>

int main()
{
    int n1, n2, mul;
    printf("Enter the number1: ");
    scanf("%d", &n1);

    printf("Enter the number2: ");
    scanf("%d", &n2);

    mul = n1 * n2;
    printf("Mul of %d and %d is: %d\n", n1, n2, mul);

    return 0;
}