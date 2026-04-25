/*Wap for find the largest element of each column.*/
#include <stdio.h>

int main()
{
    int rows;
    printf("Enter the number of rows : ");
    scanf("%d", &rows);

    int cols;
    printf("Enter the number of columns : ");
    scanf("%d", &cols);

    int arr[rows][cols];
    printf("Enter the elements of the matrix : \n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int larg_cols[cols];

    for(int i = 0; i < cols; i++)
    {
        int larg = arr[0][i];//why because of the changes shude occure in colum
        for(int j = 1; j < rows; j++)//why j = 1, what arr[0][0] > arr[0][0] no need for checking this.
        {
            if(arr[j][i] > larg)
            {
                larg = arr[j][i];
            }
        }
        larg_cols[i] = larg;
    }

    printf("The largest elements in each cols : \n");
    for(int i = 0; i < cols; i++)
    {
        printf("%d\n", larg_cols[i]);
    }
    return 0;
}