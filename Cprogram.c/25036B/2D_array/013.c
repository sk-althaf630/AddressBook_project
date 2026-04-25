/*wap for print both diagonal of 2D array in X pattern format.[square type] */
#include <stdio.h>
int main()
{
    int n;
    printf("Enter the size of the square matrix : ");
    scanf("%d", &n);

    int arr[n][n];
    printf("Enter the elements of the matrix : \n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("X pattern of diagonals matrix : \n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j || i+j == n - 1)
            {
                printf("%d ", arr[i][j]);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}