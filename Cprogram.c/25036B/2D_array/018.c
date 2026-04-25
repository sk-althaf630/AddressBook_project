/*Wap for reverse each col of the 2D array.
sample input :- 1  2  3
                4  5  6
                7  8  9
sample output:- Swap steps:
                swap 0: arr[0][0] ↔ arr[2][0] → 1 ↔ 7
                swap 1: arr[1][0] ↔ arr[1][0] → 4 ↔ 4

                swap 0: arr[0][1] ↔ arr[2][1] → 2 ↔ 8
                swap 1: arr[0][1] ↔ arr[1][1] → 5 ↔ 5

                swap 0: arr[0][2] ↔ arr[2][2] → 3 ↔ 9
                swap 1: arr[1][2] ↔ arr[1][2] → 6 ↔ 6


                After:
                7 8 9
                4 5 6
                1 2 3*/

#include <stdio.h>

int main() {
    int rows, cols;

    // Prompt user for dimensions
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int arr[rows][cols];  // Variable Length Array

    // Input matrix
    printf("Enter %d x %d matrix elements row by row:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // Print original matrix
    printf("\nBefore matrix reverse:\n");
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }

    // Reverse each column
    for (int c = 0; c < cols; c++) 
    {
        int top = 0, bottom = rows - 1;
        while (top < bottom) 
        {
            int temp = arr[top][c];
            arr[top][c] = arr[bottom][c];
            arr[bottom][c] = temp;
            top++;
            bottom--;
        }
    }

    // Print updated matrix
    printf("\nAfter matrix reverse:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}