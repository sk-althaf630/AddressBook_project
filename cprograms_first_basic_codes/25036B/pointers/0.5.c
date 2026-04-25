#include <stdio.h>
int *fun(void)
{
   static int i = 123;
    return &i;
}
int main()
{
    int * res;
    res = fun();
    printf("Res= --> %d\n", *res);
    return 0;
}