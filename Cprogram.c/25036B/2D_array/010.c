/*Wap for print transpose of 2D array using func (without extra space). 
sample input:- 1 2 3
               4 5 6
sample output:- 1 4
                2 5
                3 6*/
#include <stdio.h>
void transpose(int rows, int cols, int ptr[][cols]);
/*- The first dimension (rows) can be left empty ([]) because it doesn’t affect how elements are accessed — it’s just the number of blocks.
- The second dimension (cols) must be fixed (or passed as a constant) because the compiler needs to compute the address of arr[i][j] as:
           address = base + (i.cols + j) . sizeof(int)*/

int main()
{
    int rows;
    printf("Enter the number of rows : ");
    scanf("%d", &rows);

    int cols;
    printf("Enter the number of columns : ");
    scanf("%d", &cols);

    int arr[rows][cols];
    printf("Enter the elements of matrix(%d X %d = %d) : \n", rows, cols, rows*cols);
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    transpose(rows,cols, arr);

    return 0;
}

//this method can applycable for any type of matrixs.
void transpose(int rows, int cols, int ptr[][cols])
{
    printf("The Transposed array is : \n");
    for(int i = 0; i < cols; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            printf("%d ", ptr[j][i]);
        }
        printf("\n");
    }
}