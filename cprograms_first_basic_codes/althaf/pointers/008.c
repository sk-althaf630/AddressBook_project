/*WAP to union the two arrays with pointers
    sample input:- 1 2 3 4 5
    sample output:-y n y n y*/

#include <stdio.h>
int unio(int *ptr1,int *ptr2,int size1,int size2,int *ptr);
int check(int *ptr,int s, int n);

int main()
{
    int size1;
    printf("Enter the size of an array: ");
    scanf("%d", &size1);

    int arr1[size1];
    printf("Enter the elements of array: ");
    for(int i = 0; i < size1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    int size2;
    printf("Enter the size of an array: ");
    scanf("%d", &size2);

    int arr2[size2];
    int i;
    printf("Enter the elements of array: ");
    for(i = 0; i < size2; i++);
    {
        scanf("%d", &arr2[i]);
    }


    int size3 = size1 + size2;
    int arr[size3];
    int ret = unio(arr1,arr2,size1,size2,arr);
    for(int i = 0; i < ret; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
int unio(int *ptr1,int *ptr2,int size1,int size2,int *ptr)
{
    int s = 0;
    for(int i = 0; i < size1; i++)
    {
        if(check(ptr,s,ptr1[i]) == 0)
        {
            ptr[s] = ptr1[i];
            s++;
        }
    }
    for(int i = 0; i < size2; i++)
    {
        if(check(ptr,s,ptr2[i]) == 0)
        {
            ptr[s] = ptr2[i];
            s++;
        }
    }
    return s;
}
int check(int *ptr,int s, int n)
{
    for(int i = 0; i < s; i++)
    {
        if(ptr[i] == n)
        {
            return 1;
        }
    }
    return 0;
}