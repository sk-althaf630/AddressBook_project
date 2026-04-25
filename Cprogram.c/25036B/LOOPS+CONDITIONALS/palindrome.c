/* WAP to check if the number is palindrome.
(A palindrome number reads the same forwards and backwards.)
sample input :- 12321
sample output :- 12321 is a palindrome.

sample input :- 123
sample output :- 123 is not a palindrome. */

#include <stdio.h>

int main() 
{
    int n, reversed = 0, remainder, original;
    printf("Enter an integer: ");
    scanf("%d", &n);
    
    original = n;

    while (n != 0) 
    {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }

    if (original == reversed)
        printf("%d is a palindrome.\n", original);
    else
        printf("%d is not a palindrome.\n", original);

    return 0;
}