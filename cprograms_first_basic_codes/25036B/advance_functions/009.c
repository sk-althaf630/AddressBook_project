#include<stdio.h>
int fun()
{
    printf("Helloworld\n");
    return 07;
}

int main()
{
    int (*ptr)() = &fun;
    printf("Address of main ---> %p\n",main);
    printf("Address of main ---> %p\n",&main);
    printf("Address of fun ---> %p\n",fun);
    printf("Address of fun ---> %p\n",&fun);
    printf("Address of ptr ---> %p\n",ptr);
    printf("return of fun ---> %d\n",ptr());
    printf("return of fun --> %d\n",fun());

    printf("Size of ptr ----> %lu\n",sizeof(ptr));

    return 0;
}