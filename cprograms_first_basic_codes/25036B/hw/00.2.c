/*Description
     Date:-13 0ct 25
     time:-5:30h
     code name:-multiplication of 2 variables*/

#include <stdio.h>

int main()
{
    int num1, num2;

    printf("Enter the numbers: ");
    scanf("%d%d", &num1, &num2);

    int multipli = num1 * num2;

    printf("Answer is %d\n", multipli);

    return 0;
}