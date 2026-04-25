#include <stdio.h>
int main()
{
    int size, i;
    printf("enter the size of array: ");
    scanf("%d", &size);
    int arr1[size];
    printf("enter the elements of first array: ");
  
    for(i = 0; i < size; i++)
    {
        scanf("%d", &arr1[i]);
    }
    int arr2[size];
    printf("enter the elements of second array: ");
    for(i = 0; i < size; i++)
    {
        scanf("%d", &arr2[i]);

    }
    int res[size];
    for(i = 0; i < size; i++)
    {
      res[i] = arr1[i] * arr2[i]; 
        printf("%d", res[i]);
    }
    printf("\n");
    return 0;
}