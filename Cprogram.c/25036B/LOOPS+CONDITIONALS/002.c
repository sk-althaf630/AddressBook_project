/* WAP to check the number is +ve/-ve/0.
sample input :- -15
sample output :- -15 is negative.

sample input :- 0
sample output :- 0 is zero. */

#include <stdio.h>

int main() 
{
    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if(num > 0) 
    {
        printf("%d is positive.\n", num);
    } 
    else if(num < 0) 
    {
        printf("%d is negative.\n", num);
    } 
    else 
    {
        printf("%d is zero.\n", num);
    }
    
    return 0;
}