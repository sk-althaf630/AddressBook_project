/* WAP to count digits of a given integer.
sample input :- 4562
sample output :- Number of digits: 4 */

#include <stdio.h>

int main() 
{
    long long n;
    int count = 0;
    
    printf("Enter an integer: ");
    scanf("%lld", &n);
    
    // Handle 0 explicitly
    if (n == 0) count = 1;

    while (n != 0) 
    {
        n /= 10;
        ++count;
    }
    
    printf("Number of digits: %d\n", count);
    
    return 0;
}