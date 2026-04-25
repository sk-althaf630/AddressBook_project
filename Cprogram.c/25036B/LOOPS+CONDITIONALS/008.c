/* WAP to find the factorial of a given number.
sample input :- 5
sample output :- Factorial of 5 is 120. */
#include <stdio.h>

int main() 
{
    int n;
    long long fact = 1;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0)
        printf("Error! Factorial of a negative number doesn't exist.\n");
    else 
    {
        for (int i = 1; i <= n; ++i) 
        {
            fact *= i;
        }
        printf("Factorial of %d is %lld.\n", n, fact);
    }
    return 0;
}