#include <stdio.h>
int main()
{
    int limit, i, sum=0;
    printf("Enter the number:");
    scanf("%d", &limit);

    printf("Even numbers (2 to %d):\n",limit);

    for(i=0;i<limit;i=i+2)
    {
        sum=sum+i;
        printf("%d ", i);
    }
    printf("\nSum of %d even numbers:%d\n", limit,sum);
    return 0;
}