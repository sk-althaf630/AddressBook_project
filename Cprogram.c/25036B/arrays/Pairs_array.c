/*
Find possible pairs from the array whose sum is given by the user.

Enter the size of the array : 5
Enter the elements of the array : 1 2 3 4 5
Enter the target sum : 6
Pairs with sum 6 are:
(1, 5)
(2, 4)
*/

#include <stdio.h>

int main()
{
    int size, target;
    printf("Enter the size of the array : ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array : ");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target sum : ");
    scanf("%d", &target);

    printf("Pairs with sum %d are:\n", target);
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++) // start from i+1 to avoid repeating pairs
        {
            if(arr[i] + arr[j] == target)
            {
                printf("(%d, %d)\n", arr[i], arr[j]);
            }
        }
    }

    return 0;
}