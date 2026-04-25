#include <stdio.h>
void input(int *,int);
void display(int *,int);
void square(int *,int);

int main()
{
    int size;
    printf("enter the size: ");
    scanf("%d", &size);

    int arr[size];

    printf("enter the elements: ");
    input(arr,size);


    printf("you have store of D: ");
    display(arr,size);

    printf("you have store of S: ");
    square(arr,size);

}
void input(int *ptr, int size)
{
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &ptr[i]);
    }
}

void display(int *ptr, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", *(ptr + i));
    }
    printf("\n");
}
void square(int *ptr, int size)
{
    for(int i = 0; i < size; i++)
    {
        //*ptr[i] = *ptr[i] * *ptr[i];
        ptr[i] = ptr[i]*ptr[i];
        printf("%d ", *(ptr + i));
    }
    printf("\n");
}
