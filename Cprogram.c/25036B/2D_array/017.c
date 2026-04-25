/*wap for reverse each row of the 2D array. 
sample input :- 1  2  3
                4  5  6
                7  8  9
sample output:- Swap steps:
                Row 0: arr[0][0] ↔ arr[0][2] → 1 ↔ 3
                Row 1: arr[1][0] ↔ arr[1][2] → 4 ↔ 6
                Row 2: arr[2][0] ↔ arr[2][2] → 7 ↔ 9

                After:
                3 2 1
                6 5 4
                9 8 7*/
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

    printf("Before matrix reverse : \n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    //reversing the matrix only rows.
    for(int i = 0; i < rows; i++)
    {
        //cols/2 why because of 3/2 = 1 (4 5 6) <---> (6 5 4) the center element will be same
        for(int j = 0; j < cols/2; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[i][cols - j - 1];
            arr[i][cols - j - 1] = temp;
        }
    }

    printf("After matrix reverse : \n");
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