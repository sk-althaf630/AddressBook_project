#include <stdio.h>
int main()
{
    int size, i,j;
    printf("enter the size of array: ");
    scanf("%d", &size);
    int arr[size];
    printf("enter the elements of  array: ");
    for(i=0; i< size;i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i =0;i < size-1;i++)
    {
        for(j =0;j< size - 1-i;j++)
        {
            if(arr[j]> arr[j+1])
            {
                int tamp = arr[j];
                arr[j]= arr[j+1];
                arr[j+1]=tamp;
            }
        }
    }
    printf("stored array:\n");
    for(i=0;i<size;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}