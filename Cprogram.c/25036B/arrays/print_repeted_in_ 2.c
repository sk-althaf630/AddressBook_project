/*
Find Intersection of two arrays.
sample input:- array 1 -->1 2 3 4
               array 2 -->3 4 5 6 7
sample output:- 3 4

it avoid duplicate prints for same element

sample input:- array 1 -->1 2 2
               array 2 -->2 2
sample output:- 2
*/
#include <stdio.h>

int main()
{
    int size1, size2;
    printf("Enter the first array size : ");
    scanf("%d", &size1);
    printf("Enter the second array size : ");
    scanf("%d", &size2);

    int arr1[size1], arr2[size2];
    printf("Enter the elements of the first array : ");
    for(int i = 0;  i < size1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the elements of the second array : ");
    for(int i = 0; i < size2; i++)
    {
        scanf("%d", &arr2[i]);
    }

    printf("Intersection of two arrays : ");
    for(int i = 0; i < size1; i++)
    {
        for(int j = 0; j < size2; j++)
        {
            if(arr1[i] == arr2[j])
            {
                //check if already printed
                int already_printed = 0;
                for(int k = 0; k < i; k++)
                {
                    if(arr1[k] == arr1[i])
                    {
                        already_printed = 1;
                        break;
                    }
                }
                if(!already_printed)
                {
                    printf("%d ", arr1[i]);
                }
                break;// avoid duplicate prints for same element
            }
        }
    }
    printf("\n");

    return 0;
}