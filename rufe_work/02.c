#include <stdio.h>
int portition(int *arr, int start, int end)
{
    int pivot = arr[start];
    int p = start+1;
    int q = end;

    while(p <= q)
    {
        while(arr[p] <= pivot)
        {
            p++;
        }
        while(arr[q] > pivot)
        {
            q--;
        }

        if(p < q)
        {
            int temp = arr[p];
            arr[p] = arr[q];
            arr[q] = temp;
        }
    }

    arr[start] = arr[q];
    arr[q] = pivot;

    return q;
}
void quick_sort(int *arr, int start, int end)
{
    if(start < end)
    {
        int index = portition(arr, start, end);
        quick_sort(arr,start, index-1);
        quick_sort(arr,index+1,end);
    }
    
}

int main()
{
    int size;
    printf("Enter the sizeof the array : ");
    scanf("%d", &size);

    int arr[size];
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    quick_sort(arr,0, size-1);

    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}