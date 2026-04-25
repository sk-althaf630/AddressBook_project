/* WAP to remove 0 from a given integer.
sample input :- 10504
sample output :- Number without zeros is 154 */

#include <stdio.h>

int main() 
{
    int num, result = 0, multiplier = 1, remainder;
    
    printf("Enter an integer: ");
    scanf("%d", &num);

    while (num > 0) 
    {
        remainder = num % 10;
        if (remainder != 0) 
        {
            result = result + remainder * multiplier;
            multiplier *= 10;
        }
        num /= 10;
    }

    printf("Number without zeros is %d\n", result);
    return 0;
}