/*Print array elements in reverse order.
sample input :- 1 2 3 4 5
sample output :- 5 4 3 2 1*/
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

    for(int i = 0; i < size/2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }

    printf("After reverse the array : ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
