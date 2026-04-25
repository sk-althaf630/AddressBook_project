/*revers the array by not using bobble sort
sample i/p:- 1 2 3 4 5
sample o/p:- 5 4 3 2 1
*/

#include <stdio.h>
int main()
{
    int size;
    printf("Enter the array size: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the array elements: ");
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
    printf("Revesed array: ");
    for(int i = 0; i <  size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}