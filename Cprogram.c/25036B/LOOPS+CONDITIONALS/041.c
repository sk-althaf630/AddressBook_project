/* WAP to Print pascal’s triangle.
sample input :- 5
sample output :- 
        1 
      1   1 
    1   2   1 
  1   3   3   1 
1   4   6   4   1 

*/

#include <stdio.h>

int main() 
{
    int rows, coef = 1;
    
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    for (int i = 0; i < rows; i++) 
    {
        // Print leading spaces
        for (int space = 1; space <= rows - i; space++) 
        {
            printf("  ");
        }

        for (int j = 0; j <= i; j++) 
        {
            if (j == 0 || i == 0) 
            {
                coef = 1;
            } 
            else 
            {
                coef = coef * (i - j + 1) / j;
            }
            printf("%4d", coef);
        }
        printf("\n");
    }

    return 0;
}