#include <stdio.h>
#include <stdlib.h>

int acced(const void * a, const void *b)
{
    return *(double *)a > *(double*)b;
}
int dcced(const void *a,const void *b)
{
    return *(double*)a < *(double*)b;
}
void print(double arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%g ", arr[i]);
    }
    printf("\n");
}
int main()
{
    double arr[] ={-23.55, 77.88, 65.77, 98.77, 78.90};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("bofer the sowping ------>\n");
    print(arr,n);
    qsort(arr,n,sizeof(double),acced);

    printf("after the swaping---->\n");
    print(arr,n);

    qsort(arr,n,sizeof(double),dcced);
    printf("after the swaping---->\n");
    print(arr,n);

    return 0;
}

