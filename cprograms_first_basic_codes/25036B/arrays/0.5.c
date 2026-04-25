#include <stdio.h>
int main()
{
    int size, i, max1, max2;
    printf("Enter the size of array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of array: ");
    for(i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
     max1 = arr[0];
     max2 = 0;
    for(i = 1; i < size; i++)
    {
        if(arr[i] > max1)
        {
            max2 = max1;
            max1 = arr[i];
        }
        else if(arr[i] > max2 && arr[i] < max1)
        {
             max2 = arr[i];
        }
    }
    printf("The first largest element is: %d\n", max1);
    printf("The second largest element is: %d\n", max2); 
    return 0;     
}