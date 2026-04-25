/*
Find the Power set of a unique array. [2^n-1].

Enter the size of the array : 3
Enter the elements of the array : 1 2 3
Power set (excluding empty set):
{ 1 }
{ 2 }
{ 1 2 }
{ 3 }
{ 1 3 }
{ 2 3 }
{ 1 2 3 }
*/

#include <stdio.h>
int power(int i, int size)
{
    int res = 1;
    for(int j = 0; j < size; j++)
    {
        res *= 2;
    }

    return res;
}

int main()
{
    int size;
    printf("Enter the size of the array : ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array : ");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int total = power(2, size);  // total subsets = 2^n

    printf("Power set (excluding empty set):\n");
    for(int mask = 1; mask < total; mask++)  // start from 1 to skip empty set
    {
        printf("{ ");
        for(int j = 0; j < size; j++)
        {
            if(mask & (1 << j))  // check if j-th bit is set
            {
                printf("%d ", arr[j]);
            }
        }
        printf("}\n");
    }

    return 0;
}