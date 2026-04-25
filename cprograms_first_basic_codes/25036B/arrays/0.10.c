#include <stdio.h>//it shows the how many times pressent in arrary
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
            if(arr[j] == arr[i])
            {
                flag = 0;
                break;
            }
        }
        if(flag == 0)
        {
            continue;
        }
        int count =1;
        for(int k =i+1;k<size; k++)
        {
            if(arr[i] == arr[k])
            count++;
        }
        printf("%d --> %d time\n", arr[i],count);
    }
}