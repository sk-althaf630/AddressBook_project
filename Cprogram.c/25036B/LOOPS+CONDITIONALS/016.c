/* WAP to check if a 3-digit number is armstrong or not.
sample input :- 153
sample output :- 153 is an Armstrong number.

sample input :- 120
sample output :- 120 is not an Armstrong number. */

#include <stdio.h>

int main() 
{
    int num, originalNum, remainder, result = 0;
    
    printf("Enter a 3-digit integer: ");
    scanf("%d", &num);
    originalNum = num;

    while (originalNum != 0) 
    {
        // remainder contains the last digit
        remainder = originalNum % 10;
        
        result += remainder * remainder * remainder;
        
        // removing last digit from the original number
        originalNum /= 10;
    }

    if (result == num)
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);

    return 0;
}