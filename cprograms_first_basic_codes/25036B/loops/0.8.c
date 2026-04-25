//even
#include <stdio.h>//even
int main()
{
    int limit, i;
    printf("Enter the number:");
    scanf("%d", &limit);

    for(i=0;i<=limit;i=i+2)
    {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}