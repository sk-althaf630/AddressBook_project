/* WAP to sum and product the numbers by the pointer functions and arrays
   sample:- 
   sample output:-
                */

#include <stdio.h>
void input(int *ptr, int size);
void display(int *ptr, int size);
void fun(int *ptr, int size);

int main()
{
    int size;
    printf("Enter the size of an array: ");
    scanf("%d", &size);
    
    int arr[size];
    printf("Enter the elements of an array: ");
    input(arr,size);

    printf("Display the  stored elements: \n");
    display(arr,size);

    printf("Display the sumed elements: \n");
    fun(arr,size);
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

void fun(int *ptr, int size)
{
    for(int i = 0; i < size; i++)
    {
        ptr[i] = ptr[i] + ptr[i];
        printf("%d ", ptr[i]);
    }
    printf("\n");
}