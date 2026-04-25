/*Print only unique elements in the array.
Enter the size of the array: 6
Enter 6 elements:
1 2 3 2 4 1
Unique elements in the array are:
3 4*/

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

    printf("Unique elements in the array are:\n");
    for(int i = 0; i < size; i++)
    {
        int count = 0;
        for(int j = 0; j < size; j++)
        {
            if(arr[i] == arr[j] && i != j)
            {
                count++;
            }
        }

        if(count == 0)
        {
            printf("%d ", arr[i]);
        }
    }

    printf("\n");
    return 0;
}