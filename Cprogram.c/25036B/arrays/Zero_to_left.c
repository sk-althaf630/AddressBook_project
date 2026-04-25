/*Shift all 0’s to the left side of the array keeping other’s order the same.
sample input:-{1, 0, 2, 0, 3, 4, 0, 5}
sample output:-0 0 0 1 2 3 4 5*/

#include <stdio.h>

void shiftZerosLeft(int arr[], int n) {
    int temp[n];   // Temporary array
    int index = 0;

    // Step 1: Copy all non-zero elements into temp (preserve order)
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            temp[index++] = arr[i];
        }
    }

    // Step 2: Fill the remaining positions in temp with 0s (to the left)
    int zeroCount = n - index;
    for (int i = n - 1; i >= zeroCount; i--) {
        temp[i] = temp[i - zeroCount];
    }

    for (int i = 0; i < zeroCount; i++) {
        temp[i] = 0;
    }

    // Step 3: Copy back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

int main()
{
   int size;
   printf("Enter the size of array : ");
   scanf("%d", &size);

   int arr[size];
   printf("Enter the elements of array : ");
   for(int i = 0; i < size; i++)
   {
        scanf("%d", &arr[i]);
   }

   shiftZerosLeft(arr, size);

    printf("Array after shifting zeros to left:\n");
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
}

