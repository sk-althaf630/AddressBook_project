/* WAP to print sum of N natural numbers.
sample input :- 5
sample output :- Sum of first 5 natural numbers is 15. */
#include <stdio.h>

int main() 
{
    int n, sum = 0;
    printf("Enter N: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) 
    {
        sum += i;
    }

    printf("Sum of first %d natural numbers is %d.\n", n, sum);
    return 0;
}