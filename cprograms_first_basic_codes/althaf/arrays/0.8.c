/*bobbl sort the array in assigning order
sample i/p:- 2 3 1 5 4
sample o/p:- 1 2 3 4 5
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
    for(int i = 0; i < size - 1; i++)
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
    printf("REVERSED: ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}