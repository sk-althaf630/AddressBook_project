// print the left angle triangle with numarical
/*date :- 8 - 11- 2025*/
#include <stdio.h>
int main()
{
    int row;
    printf("enter the rows: ");
    scanf("%d", &row);
    
    for(int i = 1; i <= row; i++)
    {
        for(int j = row - 1; j >= i; j--)
        {
            printf(" ");
        }
        for(int k = 1; k <= i; k++)
        {
            printf("%d ", i);
        }
        printf("\n");
    }
}