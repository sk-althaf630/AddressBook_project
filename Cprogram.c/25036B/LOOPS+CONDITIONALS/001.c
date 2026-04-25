/* WAP to check even/odd.
sample input :- 4
sample output :- 4 is even.

sample input :- 7
sample output :- 7 is odd. */

#include <stdio.h>

int main() 
{
    int num;
    
    printf("Enter an integer: ");
    scanf("%d", &num);
    
    if(num % 2 == 0) 
    {
        printf("%d is even.\n", num);
    } 
    else 
    {
        printf("%d is odd.\n", num);
    }
    
    return 0;
}