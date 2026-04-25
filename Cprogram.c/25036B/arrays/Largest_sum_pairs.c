/*
Find the largest sum pairs in the array.

Enter the size of the array : 6
Enter the elements of the array : 1 9 3 7 5 8
Largest sum pair: (9, 8)
Sum = 17
*/

#include <stdio.h>

int main()
{
    int size;
    printf("Enter the size of the array : ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array : ");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Step 1: Find the two largest elements
    int max1 = arr[0], max2 = arr[1];
    if(max2 > max1) {
        int temp = max1;
        max1 = max2;
        max2 = temp;
    }

    for(int i = 2; i < size; i++)
    {
        if(arr[i] > max1)
        {
            max2 = max1;
            max1 = arr[i];
        }
        else if(arr[i] > max2)
        {
            max2 = arr[i];
        }
    }

    // Step 2: Print the pair and their sum
    printf("Largest sum pair: (%d, %d)\n", max1, max2);
    printf("Sum = %d\n", max1 + max2);

    return 0;
}