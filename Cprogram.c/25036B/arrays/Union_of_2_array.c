/*Find union of two arrays.
Enter size of first array: 4
Enter 4 elements of first array:
1 2 3 4
Enter size of second array: 4
Enter 4 elements of second array:
3 4 5 6
Union of two arrays:
1 2 3 4 5 6*/

#include <stdio.h>

int main() {
    int n1, n2, i, j, k = 0;

    // Input sizes of two arrays
    printf("Enter size of first array: ");
    scanf("%d", &n1);
    printf("Enter size of second array: ");
    scanf("%d", &n2);

    int arr1[n1], arr2[n2], unionArr[n1 + n2];

    // Input first array
    printf("Enter %d elements of first array:\n", n1);
    for(i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
        unionArr[k++] = arr1[i]; // Copy to union array
    }

    // Input second array
    printf("Enter %d elements of second array:\n", n2);
    for(i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    // Add elements of arr2 to unionArr if not already present
    for(i = 0; i < n2; i++) {
        int found = 0;
        for(j = 0; j < k; j++) {
            if(arr2[i] == unionArr[j]) {
                found = 1; // Duplicate found
                break;
            }
        }
        if(found == 0) {
            unionArr[k++] = arr2[i];
        }
    }

    // Print union
    printf("Union of two arrays:\n");
    for(i = 0; i < k; i++) {
        printf("%d ", unionArr[i]);
    }
    printf("\n");

    return 0;
}
