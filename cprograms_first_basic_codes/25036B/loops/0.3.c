#include <stdio.h>//printing numbers
int main()
{
    int limit;
    printf("enter the limit: ");
    scanf("%d", &limit);
    int i;

    for(i = 1; i <=limit; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}