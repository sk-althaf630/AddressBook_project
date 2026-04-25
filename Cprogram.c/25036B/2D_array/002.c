/*wap to print the input in square shape
    sample input:- promte the to give inputs
    sample output:- by row and colum by
                   1 3 4      1 2 4
                   2 3 4  and 3 3 5
                   4 5 6      4 4 6*/

#include <stdio.h>
int main()
{
    int row, colum;
    printf("Enter the row and colum count : ");
    scanf("%d %d", &row, &colum);
    
    if(row != colum)
    {
        printf("invalid input try again\n");
        return 1;
    }
    int arr[row][colum];


    for(int i = 0; i < row; i++)
    {
        printf("Enter the row %d elements: ", i+1);
        for(int j = 0; j < colum; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < colum; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

     // Transpose in-place
    for(int i = 0; i < row; i++)
    {
        for(int j = i+1; j < colum; j++) // only upper triangle
        {
            int tamp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
    
    printf("<-------------------->\n");
    printf("After sawpping : \n");
    //colum by colum
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < colum; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}