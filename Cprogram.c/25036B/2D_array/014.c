/*print both diagonal element normally: [ sq type] 
sample input :- 1  2  3
                4  5  6
                7  8  9
sample output:- Primary Diagonal: 1 5 9
                Secondary Diagonal: 3 5 7*/
#include <stdio.h>

int main() {
    int n;
    printf("Enter size of square matrix: ");
    scanf("%d", &n);

    int matrix[n][n];

    // Input elements
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Print the matrix (for reference)
    printf("\nMatrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Print primary diagonal (top-left to bottom-right)
    printf("\nPrimary Diagonal: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", matrix[i][i]);
    }

    // Print secondary diagonal (top-right to bottom-left)
    printf("\nSecondary Diagonal: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", matrix[i][n - i - 1]);
    }

    return 0;
}