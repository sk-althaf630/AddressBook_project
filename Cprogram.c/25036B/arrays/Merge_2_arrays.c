/*
Merge second array into first array
sample input:- array 1 --> 1 2 3 4 5
               array 2 --> 6 7 8 9 10
               
sample output:- 1 2 3 4 5 6 7 8 9 10
*/
#include <stdio.h>

int main()
{
    int size1, size2;

    printf("Enter the size of first array : ");
    scanf("%d", &size1);

    printf("Enter the size of second array : ");
    scanf("%d", &size2);

    int arr1[size1], arr2[size2];

    printf("Enter the elements of the first array : ");
    for(int i = 0; i < size1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the elements of the second array : ");
    for(int i = 0; i < size2; i++)
    {
        scanf("%d", &arr2[i]);
    }

    int size3 = size1+size2;
    int out_arr[size3];
    for(int i = 0; i < size1; i++)
    {
        out_arr[i] = arr1[i]; 
    }

    for(int i = 0; i < size2; i++)
    {
        out_arr[size1 + i] = arr2[i];
    }

    printf("Merged array: ");
    for(int i = 0; i < size3; i++)
    {
        printf("%d ", out_arr[i]);
    }
    printf("\n");

    return 0;
}