//wap for print nth col of 2D array.
#include <stdio.h>

int main() {
    int rows, cols;

    // Step 1: Ask user for matrix size
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int arr[rows][cols];  // Declare 2D array

    // Step 2: Input matrix elements
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // Step 3: Ask user which col to print
    int n;
    printf("Enter col index to print (0 to %d): ", cols - 1);
    scanf("%d", &n);

    // Step 4: Validate input
    if (n < 0 || n >= cols) {
        printf("Invalid col index!\n");
        return 1; // Exit program
    }

    // Step 5: Print nth col
    printf("col %d:\n", n);
    for (int j = 0; j < rows; j++) {
        printf("%d\n", arr[j][n]);
    }

    return 0;
}