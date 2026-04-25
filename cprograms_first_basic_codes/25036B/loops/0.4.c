#include <stdio.h>//Reverseal of natual number
int main()
{
    int limit, i;
    printf("enter the limit: ");
    scanf("%d", &limit);

    for(i=limit; i>=1; i--)
    {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}