//wap for print nth row of 2D array.
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
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // Step 3: Ask user which row to print
    int n;
    printf("Enter row index to print (0 to %d): ", rows);
    scanf("%d", &n);

    // Step 4: Validate input
    if (n < 0 || n > rows) {
        printf("Invalid row index!\n");
        return 1; // Exit program
    }

    // Step 5: Print nth row
    printf("Row %d:\n", n);
    for (int j = 1; j <= cols; j++) {
        printf("%d ", arr[n][j]);
    }
    printf("\n");

    return 0;
}