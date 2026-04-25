/* WAP to do some questions using the ternary operator.
sample input :- 10 25
sample output :- 
Max of 10 and 25 is 25.
10 is Even.
*/

#include <stdio.h>

int main() 
{
    int a, b, max;
    
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    // Question 1: Find Max
    max = (a > b) ? a : b;
    printf("Max of %d and %d is %d.\n", a, b, max);

    // Question 2: Check Even/Odd
    (a % 2 == 0) ? printf("%d is Even.\n", a) : printf("%d is Odd.\n", a);

    return 0;
}