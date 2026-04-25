/*
Remove duplicates from the array and create a new array.
sample input:- 1 2 3 4 5 5
sample output:- 1 2 3 4 5
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

    int unique[size];   // new array to store unique elements
    int uniqueCount = 0;

    for(int i = 0; i < size; i++)
    {
        int isDuplicate = 0;

        // check if arr[i] already exists in unique[]
        for(int j = 0; j < uniqueCount; j++)
        {
            if(arr[i] == unique[j])
            {
                isDuplicate = 1;
                break;
            }
        }

        // if not duplicate, add to unique[]
        if(!isDuplicate)
        {
            unique[uniqueCount++] = arr[i];
        }
    }

    // print the new array
    printf("Array after removing duplicates: ");
    for(int i = 0; i < uniqueCount; i++)
    {
        printf("%d ", unique[i]);
    }
    printf("\n");

    return 0;
}