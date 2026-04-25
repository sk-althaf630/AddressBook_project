/*Check array is palindrome or not.
Enter the size of the array: 5
Enter 5 elements:
1 2 3 2 1
The array is a palindrome.*/

#include <stdio.h>

int main() {
    int n, i, flag = 1;

    // Input array size
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Check palindrome
    for(i = 0; i < n/2; i++) {
        if(arr[i] != arr[n - i - 1]) {
            flag = 0; // Not palindrome
            break;
        }
    }

    if(flag == 1)
        printf("The array is a palindrome.\n");
    else
        printf("The array is NOT a palindrome.\n");

    return 0;
}