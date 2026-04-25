/* WAP to find GCD/HCF of two numbers.Greatest Common Divisor / Highest Common Factor
sample input :- 12 15
sample output :- GCD of 12 and 15 is 3. */

#include <stdio.h>

int main() 
{
    int n1, n2, result;
    
    printf("Enter two integers: ");
    scanf("%d %d", &n1, &n2);

    for(int i = 1; i <= n1 && i <= n2; ++i)
    {
        // Checks if i is factor of both integers
        if(n1 % i == 0 && n2 % i == 0)
           result = i;
    }

    printf("GCD of %d and %d is: %d\n", n1, n2, result);
    printf("HCF of %d and %d is: %d\n", n1, n2, result);
    return 0;
}