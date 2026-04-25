#include <stdio.h>
void input(int *ptr, int size)
{
    for(int i = 0;i < size; i++)
    {
        scanf("%d", &ptr[i]);
    }
}

void display(int *ptr, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", ptr[i]);
    }
    printf("\n");
}

void fun(int *ptr, int size)
{
    for(int i = 0; i < size; i++)
    {
        ptr[i] = ptr[i] % 2;
     if(ptr[i] == 0)
    {
        printf("not prime number\n");
    }
    else 
    {
        printf("prime number\n");
    }
    }
}
int main()
{
    int size;
    printf("enter the size: ");
    scanf("%d", &size);

    int arr[size];
    printf("enter the elements: ");
    input(arr,size);

    printf("Your saved elements are: ");
    display(arr,size);

    fun(arr,size);
}