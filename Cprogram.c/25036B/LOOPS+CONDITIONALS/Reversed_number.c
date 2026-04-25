/* WAP reverse an integer number.
sample input :- 1234
sample output :- Reversed number is 4321 */

#include <stdio.h>

int main() 
{
    int num, result = 0, remainder;
    
    printf("Enter an integer: ");
    scanf("%d", &num);

    while (num != 0) 
    {
        remainder = num % 10;
        result = result * 10 + remainder;
        num /= 10;
    }

    printf("Reversed number is %d\n", result);

    return 0;
}