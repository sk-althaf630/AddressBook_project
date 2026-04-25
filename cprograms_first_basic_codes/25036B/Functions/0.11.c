



#include <stdio.h>
void fun(int n)
{
    //base condition
    if(n< 1)
    {
        return;
    }
    else
    {
        fun(n - 1);
        printf("hello");
    }
    printf("\n");
}

int main()
{
    fun(3);
}