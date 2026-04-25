#include<stdio.h>
int main()
{
    int arr[5]={12,15,17,19,21};

    printf("arr -- %d\n", arr);\
    printf("arr[0] -- %d\n", &arr[0]);
    printf("&arr -- %d\n", &arr);

    printf("arr+1 -- %d\n", arr+1);\
    printf("arr[0]+1 -- %d\n", &arr[0]+1);
    printf("&arr+1 -- %d\n", &arr+1);
}