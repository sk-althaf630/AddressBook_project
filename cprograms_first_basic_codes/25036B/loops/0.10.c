#include <stdio.h>
int main()
{
    int limit, i, sum=0;
    printf("Enter the number:");
    scanf("%d", &limit);

    for(i=1;i<=limit;i+=2)
    {
        sum=sum+i;
        printf("%d ", i);
    }
    printf("\nSum of odd numbers(2 to %d):%d\n", limit,sum);
    return 0;
}