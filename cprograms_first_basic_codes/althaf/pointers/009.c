
 #include <stdio.h> // Only need standard input/output

// --- FUNCTION PROTOTYPES ---
int check(int *ptr, int s, int n);
int unio(int *ptr1, int size1, int *ptr2, int size2, int *ptr_union);

// --- FUNCTION DEFINITIONS ---

// Function to check for duplicates
// Returns 1 (Found) if 'n' is in 'ptr' up to 's', and 0 (Not Found) otherwise.
int check(int *ptr, int s, int n) {
    for (int i = 0; i < s; i++) {
        if (ptr[i] == n) {
            return 1;
        }
    }
    return 0;
}

// Function to compute the union
int unio(int *ptr1, int size1, int *ptr2, int size2, int *ptr_union) {
    int s = 0; // Current size/index of the union array

    // 1. Add all elements from the first array (ptr1).
    for (int i = 0; i < size1; i++) {
        ptr_union[s] = ptr1[i];
        s++;
    }

    // 2. Add elements from the second array (ptr2) if they are NOT duplicates.
    for (int i = 0; i < size2; i++) {
        if (check(ptr_union, s, ptr2[i]) == 0) {
            ptr_union[s] = ptr2[i];
            s++;
        }
    }

    return s; // Return the final size of the union
}

// --- MAIN FUNCTION ---
int main() {
    int size1, size2;
    int union_max_size;
    int union_size; 

    // --- Input for Array 1 ---
    printf("Enter the size of the first array: ");
    if (scanf("%d", &size1) != 1 || size1 <= 0) return 1;

    // VLA Declaration
    int arr1[size1];

    printf("Enter %d elements for the first array:\n", size1);
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    // --- Input for Array 2 ---
    printf("\nEnter the size of the second array: ");
    if (scanf("%d", &size2) != 1 || size2 <= 0) return 1;

    // VLA Declaration
    int arr2[size2];

    printf("Enter %d elements for the second array:\n", size2);
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    // --- Union Array Declaration ---
    // VLA for the result array
    union_max_size = size1 + size2;
    int union_arr[union_max_size]; 

    // --- Union Calculation ---
    union_size = unio(arr1, size1, arr2, size2, union_arr);

    // --- Output ---
    printf("\nUnion of the two arrays (Size: %d):\n{ ", union_size);
    for (int i = 0; i < union_size; i++) {
        printf("%d", union_arr[i]);
        if (i < union_size - 1) {
            printf(", ");
        }
    }
    printf(" }\n");

    return 0;
}