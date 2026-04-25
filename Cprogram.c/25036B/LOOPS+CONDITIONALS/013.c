/* WAP to find combination nCr.
sample input :- 5 2
remember thatnCr=n!/r! * (n-r)!
sample output :- 5C2 = 10 */
#include <stdio.h>

long long factorial(int n) 
{
    long long fact = 1;
    for (int i = 1; i <= n; i++) fact *= i;
    return fact;
}

int main() 
{
    int n, r;
    printf("Enter n and r: ");
    scanf("%d %d", &n, &r);

    if(n < r) 
    {
        printf("Invalid input! n should be greater than or equal to r.\n");
    } 
    else 
    {
        long long nCr = factorial(n) / (factorial(r) * factorial(n - r));
        printf("%dC%d = %lld\n", n, r, nCr);
    }
    return 0;
}

