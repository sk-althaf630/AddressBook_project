#include <stdio.h>
int add(int a, int b)
{
    return a+b;
}

int subb(int a, int b)
{
    return a-b;
}

int div(int a, int b)
{
    return a/b;
}

int main()
{
    int (*fp)(int ,int);
    fp = add;
    printf("sum is %d\n", fp(10,5));

    fp = subb;
    printf("subb is %d\n",fp(10,5));

    fp = div;
    printf("divi is %d\n", fp(10,5));
}
