/* WAP to check if a number is prime or not.
sample input :- 29
sample output :- 29 is a prime number. */
#include <stdio.h>

int main() 
{
    int n, isPrime = 1;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n == 0 || n == 1) isPrime = 0;

    for (int i = 2; i <= n / 2; ++i) 
    {
        if (n % i == 0) 
        {
            isPrime = 0;
            break;
        }
    }

    if (isPrime) printf("%d is a prime number.\n", n);
    else printf("%d is not a prime number.\n", n);

    return 0;
}