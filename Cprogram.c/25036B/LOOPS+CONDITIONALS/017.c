/* WAP to check if any digit number is armstrong or not.
sample input :- 1634
sample output :- 1634 is an Armstrong number. */

#include <stdio.h>

int power(int base, int exp) 
{
    int result = 1;
    for (int i = 0; i < exp; i++) 
    {
        result *= base;
    }
    return result;
}

int main() 
{
    int num, remainder, result = 0, n = 0;

    printf("Enter an integer: ");
    scanf("%d", &num);

    // Count number of digits
    int temp = num;
    while (temp != 0) 
    {
        temp /= 10;
        n++;
    }

    // Calculate sum of digits raised to power n
    temp = num;
    while (temp != 0) 
    {
        remainder = temp % 10;
        result += power(remainder, n);  // custom function instead of pow()
        temp /= 10;
    }

    if (result == num)
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);

    return 0;
}
