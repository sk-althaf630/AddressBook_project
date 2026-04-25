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
    for(i=0; i< size;i++)
    {
        int flag = 1;
        for(j=0;j<i;j++)
        {
            if(arr[i] == arr[j])
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            printf("%d", arr[i]);
        }
    }
}