/* WAP to Find the square root of an integer correct up to 2 decimal places.
(Using Newton-Raphson method for manual calculation without <math.h>)
sample input :- 10
sample output :- Square root of 10 is 3.16 */

#include <stdio.h>

int main() 
{
    int n;
    float sqrt, temp;
    
    printf("Enter an integer: ");
    scanf("%d", &n);

    if (n < 0) 
    {
        printf("Square root of negative number is not real.\n");
        return 1;
    }

    sqrt = n / 2.0;
    temp = 0.0;

    // Iterate until the precision is achieved
    while (sqrt != temp) 
    {
        temp = sqrt;
        sqrt = (n / temp + temp) / 2;
    }

    printf("Square root of %d is %.2f\n", n, sqrt);

    return 0;
}