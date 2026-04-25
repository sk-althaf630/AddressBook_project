#include <stdio.h>
int main()
{
    int i, j, limit;
    int count;
    printf("Enter the limit: ");
    scanf("%d", &limit);

    for(i = 2; i <= limit; i++)
    {
        count = 0;
        for(j = 2; j * j <= i; j++)
        {
            if(i % j == 0)
            {
                count = 1;
                break;
            }
        }
        if(count == 0)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}