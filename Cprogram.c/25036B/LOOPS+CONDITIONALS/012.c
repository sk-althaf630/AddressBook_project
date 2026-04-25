/* WAP to print x^y.
sample input :- 2 3
sample output :- 2^3 = 8 */
#include <stdio.h>

int main() 
{
    int x, y;
    long long result = 1;
    printf("Enter base (x) and exponent (y): ");
    scanf("%d %d", &x, &y);

    for(int i = 0; i < y; i++) 
    {
        result *= x;
    }
    printf("%d^%d = %lld\n", x, y, result);
    return 0;
}