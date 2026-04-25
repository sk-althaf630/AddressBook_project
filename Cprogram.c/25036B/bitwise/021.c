/*
Find the missing number in the group of n natural numbers.

Array: {1, 2, 4, 5, 6}
Expected range: 1..6
Missing number: 3
*/

#include <stdio.h>

int main() {
    int arr[] = {1, 2, 4, 5, 6};  // Example: missing 3
    int n = 6;  // total numbers should be 1..6

    int xor_all = 0, xor_arr = 0;

    // XOR of 1..n
    for (int i = 1; i <= n; i++) {
        xor_all ^= i;
    }

    // XOR of array elements
    for (int i = 0; i < n-1; i++) {
        xor_arr ^= arr[i];
    }

    int missing = xor_all ^ xor_arr;
    printf("Missing number is: %d\n", missing);
    return 0;
}
// #include <stdio.h>

// int main() {
//     int arr[] = {1, 2, 4, 5, 6};  // Example: missing 3
//     int n = 6;  // total numbers should be 1..6
//     int sum = 0;

//     for (int i = 0; i < n-1; i++) {
//         sum += arr[i];
//     }

//     int expected = n * (n + 1) / 2;
//     int missing = expected - sum;

//     printf("Missing number is: %d\n", missing);
//     return 0;
// }