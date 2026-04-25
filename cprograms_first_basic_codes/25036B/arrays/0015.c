#include<stdio.h>
int main()
{
    int row, col;
    printf("enter the size of row and columns:");
    scanf("%d%d", &row, &col);
    int arr[row][col];

    for(int i=0; i<row; i++)
    {
        printf("Enter the %dth row: ", i+1);
        for(int j=0; j<col; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    //row by row
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    //col by col
    for(int i=0; i<col; i++)
    {
        for(int j=0; j<row; j++)
        {
            printf("%d\t", arr[j][i]);
        }
        printf("\n");
    }
}