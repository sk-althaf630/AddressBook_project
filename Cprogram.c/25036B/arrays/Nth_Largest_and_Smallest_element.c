/*
Find the Nth Largest/Smallest element of the array.

Enter the size of the array : 6
Enter the elements of the array : 10 4 7 2 9 5
Enter N (position): 2
2-th smallest element = 4
2-th largest element  = 9
*/

#include <stdio.h>

int main()
{
    int size, N;
    printf("Enter the size of the array : ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array : ");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter N (position): ");
    scanf("%d", &N);

    // Step 1: Sort the array (ascending order)
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Step 2: Find Nth smallest and Nth largest
    if(N > 0 && N <= size)
    {
        int nthSmallest = arr[N - 1];       // index N-1
        int nthLargest  = arr[size - N];   // index size-N

        printf("%d-th smallest element = %d\n", N, nthSmallest);
        printf("%d-th largest element  = %d\n", N, nthLargest);
    }
    else
    {
        printf("Invalid N! Must be between 1 and %d\n", size);
    }

    return 0;
}