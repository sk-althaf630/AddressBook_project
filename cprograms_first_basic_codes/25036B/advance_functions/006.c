#include <stdio.h>
int add(int count, ...);
#include <stdarg.h>
int main()
{
    printf("The sum is %d\n", add(3,10,20,30));
    printf("The sum is %d\n", add(5,10, 20, 30, 15, 15));
}
int add(int count, ...)
{
    va_list ap;
    va_start(ap, count);
    int sum = 0;
    for(int i = 0;i < count; i++)
    {
        sum = sum + va_arg(ap, int);
    }
    va_end(ap);
    return sum;
}