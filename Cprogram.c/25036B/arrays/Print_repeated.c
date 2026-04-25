/*Print only repeated elements in the array.
Enter the size of the array: 6
Enter 6 elements:
1 2 3 2 4 1
Repeated elements in the array are:
1 2*/

#include <stdio.h>

int main()
{
    int size;
    printf("Enter the size of an array : ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the array elements : \n");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Repeated elements in the array are:\n");

    // Check for repeated elements
    for(int i = 0; i < size; i++)
    {
        int count = 0;
        for(int j = i + 1; j < size; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
                break;// Found a duplicate, no need to check further
            }
        }

        if(count > 0)
        {
            printf("%d ", arr[i]);
        }
    }

    printf("\n");
    return 0;
}