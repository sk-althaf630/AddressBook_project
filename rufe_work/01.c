#include <stdio.h>
#include <stdlib.h>
void marge(int *arr, int size_arr, int *left, int size_lef, int *right, int size_right)
{
    int i =0, j = 0, k = 0;

    while(i < size_lef && j < size_right)
    {
        if(left[i] > right[j])
        {
            arr[k++] = right[j++];
        }
        else
        {
            arr[k++] = left[i++];
        }
    }

    while(i < size_lef)
    {
        arr[k++] = left[i++];
    }

    while(j < size_right)
    {
        arr[k++] = right[j++];
    }
}
int marge_sort(int *arr, int size_arr)
{
    if(size_arr <= 1)
    {
        return 0;
    }
    int mid = size_arr/2;

    int *left = malloc(mid * sizeof(int));
    int *right = malloc((size_arr - mid) * sizeof(int));

    for(int i = 0; i < mid; i++)
    {
      left[i] = arr[i];
    }
    for(int i = mid; i < size_arr ; i++)
    {
        right[i - mid] = arr[i];
    }
    
    marge_sort(left, mid);
    marge_sort(right, size_arr-mid);
   
    marge(arr, size_arr, left, mid, right, size_arr-mid);

    free(left);
    free(right);
    return 0;
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

    marge_sort(arr,size);

    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

