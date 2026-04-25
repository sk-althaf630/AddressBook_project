/* WAP to print prime up to limit L.
sample input :- 20
sample output :- 2 3 5 7 11 13 17 19 */

#include <stdio.h>

int main() 
{
    int limit, isPrime;
    
    printf("Enter the limit L: ");
    scanf("%d", &limit);

    printf("Prime numbers up to %d are: ", limit);
    for(int i = 2; i <= limit; i++)
    {
        isPrime = 1;
        for(int j = 2; j <= i / 2; j++)
        {
            if(i % j == 0)
            {
                isPrime = 0;
                break;
            }
        }
        if(isPrime == 1)
        {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}