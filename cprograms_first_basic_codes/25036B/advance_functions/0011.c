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
int calculate(int (*fp)(int, int),int a,int b)
{
    return fp(a,b);
}

int main()
{
    printf("Sum ---> %d\n",calculate(add,5,10));
    printf("Subb ---> %d\n",calculate(subb,50,10));
    printf("divi ---> %d\n",calculate(div,10,5));
    return 0;
}