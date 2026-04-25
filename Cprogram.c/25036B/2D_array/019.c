/*wap for sort each row of 2D array(asc/des). */

#include <stdio.h>
int main()
{
    int rows, order;
    printf("Enter the number of rows : ");
    scanf("%d", &rows);

    int cols;
    printf("Enter the number of columns : ");
    scanf("%d", &cols);

    int arr[rows][cols];
    printf("Enter the elements of matrix (%d X %d = %d) : \n", rows, cols, rows*cols);
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Enter 1 for Ascending, 2 for Descending sort: ");
    scanf("%d", &order);


    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols-1; j++)
        {
            for(int k = 0; k < cols - j - 1; k++)
            {
                if((order == 1 && arr[i][k] > arr[i][k+1]) || 
                   (order == 2 && arr[i][k] < arr[i][k+1]))
                {
                    int temp = arr[i][k];
                    arr[i][k] = arr[i][k+1];
                    arr[i][k+1] = temp;
                }
            }
        }
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}