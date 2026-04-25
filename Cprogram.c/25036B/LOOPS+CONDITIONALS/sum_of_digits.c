/* WAP to find the sum of digits of a given number.
sample input :- 1234
sample output :- Sum of digits: 10 */

#include <stdio.h>

int main() 
{
    int num, sum = 0, remainder;
    
    printf("Enter an integer: ");
    scanf("%d", &num);

    while (num != 0) 
    {
        remainder = num % 10;
        sum += remainder;
        num /= 10;
    }

    printf("Sum of digits: %d\n", sum);
    return 0;
}
