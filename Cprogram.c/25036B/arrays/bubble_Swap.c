/*wap for swapping the acending order.
sample i/p:- 5 4 3 2 1
sample o/p:- 1 2 3 4 5*/

#include <stdio.h>
int main()
{
    int size;
    printf("Enter the size of the arry: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the arry: ");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < size-1; i++)
    {
        for(int j = 0; j < size - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("After swapping : \n");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}