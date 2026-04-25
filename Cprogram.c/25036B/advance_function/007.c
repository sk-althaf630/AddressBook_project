//this is the basic programe of variadic function

#include <stdio.h>
#include <stdarg.h>

int add(int count, ...)//count = it store the count of argument passing
{
    va_list ap;//va_list is used for declareing variable like int,char
    va_start(ap, count);//function of passing argument list and count of argument
    int sum = 0;
    for(int i = 0; i < count; i++)
    {
        sum += va_arg(ap, int);//ap= list of argument , her argument is int
    }
    va_end(ap);//endes the opended list
    return sum;
}
int main()
{
    printf("SUM = %d\n", add(4,10,20,30,40));
    printf("SUM = %d\n", add(5, 1,2,3,4,5));
}