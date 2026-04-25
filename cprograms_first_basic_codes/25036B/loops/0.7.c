//odd
#include <stdio.h>
int main()
{
    int limit;
    int i;
    printf("Enter the number:");
    scanf("%d", &limit);

    for(i=1;i<=limit;i=i+2)
    {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}