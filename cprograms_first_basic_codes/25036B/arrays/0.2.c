#include <stdio.h>
int main()
{
    int size, i;

    printf("Enter the size of the array:");
    scanf("%d", &size);
    int arr[size];

    printf("enter the elements of array:");
    for(i = 0;i< size; i++)
    {
        scanf("%d", &arr[i]);
    }
    int num;
    printf("enter thr number u are finding for: ");
    scanf("%d", &num);
    int flag = 0;
    for(i = 0; i < size; i++)
    {
        if(num == arr[i])
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
     printf("%d is present in the array\n", num);
    else
     printf("%d is not present\n", num);
    return 0;
}