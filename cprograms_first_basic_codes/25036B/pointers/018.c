#include<stdio.h>
int main()
{
    int a=10;
    int *ptr1=&a;
    int **ptr2=&ptr1;
    int ***ptr3=&ptr2;

    printf("ptr3 -- %p &ptr2 -- %p\n", ptr3, &ptr2);
    printf("ptr3 -- %p ptr1 -- %p &ptr -- %p\n", *ptr3, ptr2, &ptr1);
    printf("ptr3 -- %p ptr2 -- %p ptr1 -- %p &a -- %d\n", **ptr3, *ptr2, ptr1, &a);
    printf("ptr3 -- %d ptr2 -- %d ptr1 -- %d a -- %d\n", ***ptr3, **ptr2, *ptr1, a);
}