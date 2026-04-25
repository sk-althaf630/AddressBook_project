#include <stdio.h>
int main()
{
    int limit;
    printf("enter the limit: ");
    scanf("%d", &limit);
    int i;

    for(i = 0; i <= limit; i=i+2)
    {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}