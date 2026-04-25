#include <stdio.h>
int fact(int n)
{
    int res;
    if(n <= 1)
    {
        return 0;
    }
    else
    {
        return res =fact(n - 1)+fact(n - 2);
        printf("%d", res);
    }
}
int main()
{
    fact(10);
}