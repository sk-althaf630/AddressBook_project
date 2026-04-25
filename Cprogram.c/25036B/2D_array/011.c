/*Wap for find the sum of 2 matrices (both dim exactly the same).
sample input:- 1 2 3   +  1 2 3
               4 5 6   +  4 5 6
sample output:- 2 4 6
                8 10 12*/

#include <stdio.h>
int main()
{
    int rows;
    printf("Enter the number of rows : ");
    scanf("%d", &rows);

    int cols;
    printf("Enter the number of cols : ");
    scanf("%d", &cols);

    int arr[rows][cols];
    printf("Enter the elements of 1st matrix (%d X %d = %d) is : \n", rows, cols, rows*cols);
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int prr[rows][cols];
    printf("Enter the elements of 2nd matrix (%d X %d = %d) is : \n", rows, cols, rows*cols);
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            scanf("%d", &prr[i][j]);
        }
    }

    int result_matrix[rows][cols];

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            result_matrix[i][j] = arr[i][j] + prr[i][j];
        }
    }

    printf("The sum of 2 matrices : \n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%d ", result_matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}