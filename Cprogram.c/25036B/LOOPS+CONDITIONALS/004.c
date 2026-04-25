/* WAP to print N natural number.
sample input :- 5
sample output :- 1 2 3 4 5 */

#include <stdio.h>

int main() 
{
    int n;
    
    printf("Enter the value of N: ");
    scanf("%d", &n);
    
    if(n < 1) 
    {
        printf("Please enter a positive integer greater than 0.\n");
        return 1;
    }
    
    printf("The first %d natural numbers are: \n", n);
    for(int i = 1; i <= n; i++) 
    {
        printf("%d ", i);
    }
    printf("\n");
    
    return 0;
}