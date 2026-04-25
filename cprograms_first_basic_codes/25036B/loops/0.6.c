#include <stdio.h>
int main()
{
    int limit, i, sum=0;
    printf("enter the limit: ");
    scanf("%d", &limit);

    for(i=1; i<=limit; i++)
    {
        sum=sum+i;
    }
    printf("Sum of %d natural numbers is:%d\n",limit,sum);
    return 0;
}