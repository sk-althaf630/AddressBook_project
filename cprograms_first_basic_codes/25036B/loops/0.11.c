#include <stdio.h>
int main()
{
    int limit, i, sum=0;
    printf("Enter the number:");
    scanf("%d", &limit);

    int start_point=(limit/2)*2;

    for(i = start_point;i >= 0;i -= 2);
    {
        sum += i;
        printf("%d ", i);
    }
    printf("\nSum of even numbers(2 to %d):%d\n", limit,sum);
    return 0;
}