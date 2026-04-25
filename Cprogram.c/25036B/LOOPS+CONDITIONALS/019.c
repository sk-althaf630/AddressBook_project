/* WAP to check if a number is perfect or not.
(A perfect number is a positive integer that is equal to the sum of its proper divisors.)
sample input :- 28
sample output :- 28 is a Perfect number. */

#include <stdio.h>

int main() 
{
    int num, sum = 0;
    
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    for(int i = 1; i <= num / 2; i++)
    {
        if(num % i == 0)
        {
            sum += i;
        }
    }

    if(sum == num && num > 0)
        printf("%d is a Perfect number.\n", num);
    else
        printf("%d is not a Perfect number.\n", num);

    return 0;
}