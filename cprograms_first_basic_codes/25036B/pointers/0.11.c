#include <stdio.h>
void input(int *, int);
void even_odd(int *, int);
int binary(int *, int);

int main()
{
    int size;
    printf("enter the size of array: ");
    scanf("%d", &size);

    int arr[size];
    printf("enter the elements: ");
    input(arr,size);

    even_odd(arr,size);
    int bin = binary(arr,size);
}
void input(int *ptr, int size)
{
    for(int i = 0;i < size; i++)
    {
        scanf("%d", &ptr[i]);
    }
}
void even_odd(int *ptr, int size)
{
    for(int i = 0; i < size; i++)
    {
        if(ptr[i] % 2)
        {
            ptr[i] = 0;
            prinf("%d", ptr[i]);
        }
        else{
            ptr[i] = 1;
            prinf("%d", ptr[i]);
        }
    }
}
int binary(int *ptr,int size)
{
    int sum = 0;
    for(int i =size - 1);
}