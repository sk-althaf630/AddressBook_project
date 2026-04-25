/* Find the largest of N elements without using an array.
sample input :- 5 (then enters: 10, 45, 2, 78, 14)
sample output :- The largest number is 78. */

#include <stdio.h>

int main() 
{
    int n, num, max;
    
    printf("Enter the number of elements (N): ");
    scanf("%d", &n);
    
    if(n <= 0) 
    {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter number 1: ");
    scanf("%d", &max); // Assume first number is the max initially

    for(int i = 2; i <= n; i++) 
    {
        printf("Enter number %d: ", i);
        scanf("%d", &num);
        if(num > max) 
        {
            max = num;
        }
    }

    printf("The largest number is %d.\n", max);
    return 0;
}