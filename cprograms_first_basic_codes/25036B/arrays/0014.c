#include<stdio.h>
int main()
{
    int row=2, col=3;
    int arr[2][3]={{12, 13, 14},{15, 16, 17}};

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}