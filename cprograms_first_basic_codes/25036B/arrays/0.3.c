#include <stdio.h>
int main()
{
    int size, i;

    printf("Enter the size of the array");
    scanf("%d", &size);
    int arr[size];

    printf("enter the elements of array:");
    for(i = 0;i< size; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < size; i++)
    {
        if(arr[i] % 2)
         printf("%d is odd\n", arr[i]);
        else
         printf("%d is even\n", arr[i]);
    }
    return 0;
}