#include <stdio.h>
#include <stdlib.h>

void input(int arr[], int size)
{
    for(int i = 0; i <size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void print(int arr[], int size)
{
    for(int i = 0; i <size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int sa(const void *a, const void *b)
{
    return *(int*)a > *(int *)b;
}

int sd(const void *a, const void *b)
{
    return *(int*)a < *(int*)b;
}
int fsa(const void *a, const void *b)
{
    return *(int*)a > *(int*)b;
}

int fsd(const void *a, const void *b)
{
    return *(int*)a < *(int*)b;
}


int main()
{
    int size;
    printf("Enter the size : ");
    scanf("%d", &size);

    int arr[size];
    input(arr,size);
    printf("it is the before the sawping------>\n");
    print(arr, size);
    qsort(arr, size, sizeof(*arr), sa);

    printf("it is the before the sawping------>\n");
    print(arr,size);
    qsort(arr,size,sizeof(*arr),sd);
    print(arr,size);

    float prr[] = {18.3, 45.6, 67.8, 98.9, 70.5};
   // int size2 = sizeof(prr)/sizeof(prr[0]);

    printf("<------------->\n");
    qsort(prr,sizeof(prr)/sizeof(prr[0]), sizeof(*prr), fsa);
    print(prr,sizeof(prr)/sizeof(prr[0]));

    printf("<------------->\n");
    qsort(prr,sizeof(prr)/sizeof(prr[0]), sizeof(*prr), fsd);
    print(prr,sizeof(prr)/sizeof(prr[0]));

    return 0;
}