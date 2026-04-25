/*
Find the only non-repeating number in the array.

Array: {2, 3, 5, 4, 5, 3, 4}
Result: 2

Step 1: 2 ^ 3 = 1
Step 2: 1 ^ 5 = 4
Step 3: 4 ^ 4 = 0
Step 4: 0 ^ 5 = 5
Step 5: 5 ^ 3 = 6
Step 6: 6 ^ 4 = 2  ← Unique number*/

#include <stdio.h>

int main() {
    int arr[] = {2, 3, 5, 4, 5, 3, 4};  // Example array
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = 0;

    // XOR all elements
    for (int i = 0; i < n; i++) {
        result = result ^ arr[i];
    }

    printf("The non-repeating number is: %d\n", result);
    return 0;
}