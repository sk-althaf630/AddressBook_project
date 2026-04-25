#include <stdio.h>
#define clear(num, n) (num & (~((1<<n)-1)))
/*int clear(int num,int n)
{
    return num & (~((1 << n)-1));
}*/

int main()
{
    printf("%#X\n", clear(0xCD,3));
}