/* Program to find double and half of a given number using bitwise operators */

#include <stdio.h>

int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);

    int dbl = num << 1;   // left shift → multiply by 2
    int half = num >> 1;  // right shift → divide by 2 (integer division)

    printf("Double of %d is %d\n", num, dbl);
    printf("Half of %d is %d\n", num, half);

    return 0;
}