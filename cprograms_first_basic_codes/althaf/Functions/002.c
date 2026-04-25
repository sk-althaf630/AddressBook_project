/*WAP to findleader number in a array with functions
    sample input:- 12 15 3 4 5 2 3
    sample output:-15 5 3*/

#include <stdio.h>
void input(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}
void findleader(int arr[], int size)
{
    int leaders[size];
    int count = 0;
    int max_from_right = arr[size - 1];
    leaders[count++] = max_from_right;

    for(int i = size - 2; i >= 0; i--)
    {
        if(arr[i] > max_from_right)
        {
            max_from_right = arr[i];
            leaders[count++] = arr[i];
        }
    }


    printf("Leaders ---> ");
    for(int i = count - 1; i >= 0; i--)
    {
        printf("%d ", leaders[i]);
    }
    printf("\n");
}
int main()
{
    int size;
    printf("Enter the size of an array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of an array: ");
    input(arr,size);

    findleader(arr,size);
}