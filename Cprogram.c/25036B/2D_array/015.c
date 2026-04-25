/*Wap for find the sum of both diagonal elements. 
sample input :- 1  2  3
                4  5  6
                7  8  9
sample output:- Primary Diagonal sum: 1+5+9 = 15
                Secondary Diagonal sum: 3+5+7 = 15*/
#include <stdio.h>
int main()
{
    int n;
    printf("Enter the size of square matrix : ");
    scanf("%d", &n);

    int arr[n][n];
    printf("Enter the elements of square matrix : \n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    //doing sum of primary diagonal elements of matrix.
    int sum_primary_diagonal = 0;
    for(int i = 0; i < n; i++)
    {
        sum_primary_diagonal += arr[i][i];
    }

    //doing sum of secondary diagonal elements of matrix.
    int sum_secondary_diagonal = 0;
    for(int i = 0; i < n; i++)
    {
        sum_secondary_diagonal += arr[i][n - i - 1];
    }

    printf("Sum of the first diagonal = %d\nSum of the second diagonal = %d\n", sum_primary_diagonal, sum_secondary_diagonal);
}