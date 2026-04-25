#include <stdio.h>
int main()
{
    int limit;
    int i=0;
    printf("enter the limit:");
    scanf("%d", &limit);

    while (i<=limit)
    {
        printf("%d ", i);
        i=i+2;
    }
    printf("\n");
    return 0;
    
}