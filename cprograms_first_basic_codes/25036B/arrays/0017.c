#include<stdio.h>
int main()
{
    int row, col;
    printf("enter the size of row and columns:");
    scanf("%d%d", &row, &col);
    
    if(row!=col)
    {
        printf("Invlaid input\n");
        return 0;
    }
    
    int arr[row][col];
    
    for(int i=0; i<row; i++)
    {
        printf("Enter the %dth row: ", i+1);
        for(int j=0; j<col; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    
    printf("The diagonal elements are\n");
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(i==j || (i+j)==col-1)
            {
                printf("%d ", arr[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}