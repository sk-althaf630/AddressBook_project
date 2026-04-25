/* WAP to Find Largest/Smallest of two numbers.
sample input :- 10 25
sample output :- Largest is 25, Smallest is 10. */

#include <stdio.h>

int main() 
{
    int num1, num2;
    
    printf("Enter two numbers separated by a space: ");
    scanf("%d %d", &num1, &num2);
    
    if(num1 > num2) 
    {
        printf("Largest is %d, Smallest is %d.\n", num1, num2);
    } 
    else if(num2 > num1) 
    {
        printf("Largest is %d, Smallest is %d.\n", num2, num1);
    } 
    else 
    {
        printf("Both numbers are equal (%d).\n", num1);
    }
    
    return 0;
}