/* WAP to print N prime numbers.
sample input :- 5
sample output :- 2 3 5 7 11 */

#include <stdio.h>

int main() 
{
    int n, count = 0, num = 2, isPrime;
    
    printf("Enter N: ");
    scanf("%d", &n);

    printf("The first %d prime numbers are: ", n);
    while(count < n)
    {
        isPrime = 1;
        for(int i = 2; i <= num / 2; i++)
        {
            if(num % i == 0)
            {
                isPrime = 0;
                break;
            }
        }
        
        if(isPrime == 1)
        {
            printf("%d ", num);
            count++;
        }
        num++;
    }
    printf("\n");

    return 0;
}