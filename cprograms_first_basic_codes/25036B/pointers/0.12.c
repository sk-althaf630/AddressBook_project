#include <stdio.h>
void input1(int *ptr1, int size1)
{
    for(int i  = 0; i < size1; i++)
    {
        scanf("%d", &ptr1[i]);
    }
}
void input2(int *ptr2, int size2)
{
    for(int i  = 0; i < size2; i++)
    {
        scanf("%d", &ptr2[i]);
    }
}

int unio(int *ptr1, int *ptr2, int size1, int size2, int *p)
{
    int s = 0;
    for(int i =0; i <size1; i++)
    {
        if(check(p,s,ptr1[i]))
        {
            p[s] = ptr1[i];
            s++;
        }
    }
        for(int i =0; i <size1; i++)
    {
        if(check(p,s,ptr2[i]))
        {
            p[s] = ptr2[i];
            s++;
        }
    }
    return s;
}
int check(int *p, int s, int n)
{
    for(int i = 0; i < s; i++)
    {
        if(p[i] == n)
        {
            return 0;
        }
        return 1;
    }
}
int main()
{
    int size1, size2;
    printf("enter the size1: ");
    printf("enter the size2: ");
    scanf("%d %d", &size1, &size2);

    int arr1[size1];
    printf("enter the elements of arr1: ");
    input1(arr1,size1);

    int arr2[size2];
    printf("enter the elements of arr2: ");
    input2(arr2,size2);

    int arr[size1 + size2];
    int s = unio(arr1,arr2,size1,size2,arr);
    printf("res: %d", s);
}