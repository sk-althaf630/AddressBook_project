#include <stdio.h>
int *fun(void)
{
    static int num = 123;

    return &num;
}
int main()
{
    int *ret;
    ret= fun();
    printf("%d\n", *ret);
}