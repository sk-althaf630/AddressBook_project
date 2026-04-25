#include <stdio.h>
void fun(int * ptr)
{
    *ptr = 200;
}
int main()
{
    int num = 100;
    printf("Before function call\num is %d\n", num);
    fun(&num);
    printf("Before function call\num is %d\n", num);
}