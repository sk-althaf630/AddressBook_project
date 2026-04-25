/* WAP to Print Square ring pattern.
sample input :- 5
sample output :- 
* * * * * * * * * * * * * * * * */

#include <stdio.h>

int main() 
{
    int n;
    
    printf("Enter the size of the square ring: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) 
    {
        for(int j = 1; j <= n; j++) 
        {
            // Print star for first/last row or first/last column
            if(i == 1 || i == n || j == 1 || j == n) 
            {
                printf("* ");
            } 
            else 
            {
                printf("  "); // Print space inside the ring
            }
        }
        printf("\n");
    }

    return 0;
}