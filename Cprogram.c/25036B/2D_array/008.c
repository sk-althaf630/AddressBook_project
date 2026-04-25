/*Wap for find the largest element of each row.
sample input :- 1 2 3
                4 5 6
sample output :- 3
                 6 */
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
    printf("Enter the %d elements in each row : \n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int largest[rows];
    for(int i = 0; i < rows; i++)
    {
        int larg = arr[i][0];//why because i=2 arr[i][i]//arr[2][2] it will access to 2row 2element.
        for(int j = 1; j < cols; j++)
        {
            if(arr[i][j] > larg)
            {
                larg = arr[i][j];
            }
        }
        largest[i] = larg;//why because means it assign the completing of 1st 1d array cycle.
    }

    printf("The largest elements in each row : \n");
    for(int i = 0; i < rows; i++)
    {
        printf("%d\n", largest[i]);
    }

    return 0;
}