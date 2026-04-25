#include <stdio.h>
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
int accend(int a, int b)
{
    return a > b;
}

int dccend(int a, int b)
{
    return a < b;
}

void sort(int arr[], int size, int (*fp)(int, int))
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - 1 -i; j++)
        {
            if(fp(arr[j],arr[j+1]))
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    int size;
    printf("Enter the size : ");
    scanf("%d", &size);

    int arr[size];
    input(arr,size);
    printf("it is the before the sorting------>\n");
    print(arr, size);

    printf("it is the before the sorting------>\n");
    sort(arr, size, accend);
    print(arr, size);

    printf("it is sorted number in deccending order----->\n");
    sort(arr, size, dccend);
    print(arr, size);

}