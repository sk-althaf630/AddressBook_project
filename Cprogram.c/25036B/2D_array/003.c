/*Wap for  finding the avg of 2D array elements
sample input:- 1 2 3
               4 5 6
sample output:- 3.5*/

#include <stdio.h>
int main()
{
    int row, col;
    printf("Enter the row and columns of 2D array : ");
    scanf("%d %d", &row, &col);

    int arr[row][col];
    for(int i = 0; i <row; i++)
    {
        printf("Enter the row %d elements : \n", i+1);
        for(int j = 0; j < col; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int sum = 0;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
    }
    float avg = (float)sum/(row * col);

    printf("RES = %g\n", avg);
    return 0;
}