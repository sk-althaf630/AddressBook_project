/* WAP to print fundamental patterns.
sample input :- 5 (rows)
sample output :- 
Pattern 1 (Right Triangle):
* * * * * * * * * * * * * * * Pattern 2 (Pyramid):
    * * * * * * * * * * * * * * * */

#include <stdio.h>

int main() 
{
    int rows;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("\nPattern 1 (Right Triangle):\n");
    for (int i = 1; i <= rows; ++i) 
    {
        for (int j = 1; j <= i; ++j) 
        {
            printf("* ");
        }
        printf("\n");
    }

    printf("\nPattern 2 (Pyramid):\n");
    for (int i = 1; i <= rows; ++i) 
    {
        // Print spaces
        for (int space = 1; space <= rows - i; ++space) 
        {
            printf(" ");
        }
        // Print stars
        for (int j = 1; j <= i; ++j) 
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}