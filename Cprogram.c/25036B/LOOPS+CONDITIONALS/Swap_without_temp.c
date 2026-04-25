/* WAP to Swap two values without using a third variable.
sample input :- 10 20
sample output :- After swapping: a = 20, b = 10 */

#include <stdio.h>

int main() 
{
    int a, b;
    
    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);

    // Swapping logic using addition and subtraction
    a = a + b; // a now becomes 30 (if input was 10, 20)
    b = a - b; // b becomes 10 (30 - 20)
    a = a - b; // a becomes 20 (30 - 10)

    printf("After swapping: a = %d, b = %d\n", a, b);

    return 0;
}