#include <stdio.h>//reversal of sum  of odd
int main()
{
    int limit, i, sum=0;
    printf("Enter the number:");
    scanf("%d", &limit);

    int start_point=(limit+1)/2*2-1;

    for(i=start_point;i>=1;i-=2)
    {
        sum=sum+i;
        printf("%d ", i);
    }
    printf("\nSum of odd numbers(1 to %d):%d\n", limit,sum);
    return 0;
}