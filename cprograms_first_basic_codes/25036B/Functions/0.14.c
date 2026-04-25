




#include <stdio.h>
int fun(int n)
{
    if(n == 1)
    {
        return 1;
    }
    else{
        return n * fun(n -1);
    }
}
int main()
{
    int res = fun(4);
    printf("RES:  %d\n", res);
}