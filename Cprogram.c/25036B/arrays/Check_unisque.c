/*Check array is unique or not.
Enter the size of the array: 5
Enter 5 elements:
1 2 3 4 5
The array has all unique elements.

Enter the size of the array: 5
Enter 5 elements:
1 2 3 2 5
The array does NOT have unique elements.*/

#include <stdio.h>

int main() {
    int n, i, j, flag = 1;

    // Input array size
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Check uniqueness
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                flag = 0; // Duplicate found
                break;
            }
        }
        if(flag == 0) break;
    }

    if(flag == 1)
        printf("The array has all unique elements.\n");
    else
        printf("The array does NOT have unique elements.\n");

    return 0;
}