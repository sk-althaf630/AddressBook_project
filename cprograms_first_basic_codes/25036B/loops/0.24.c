#include <stdio.h>
int main()
{
    int i, j, k, n, m = 1;
    printf("enter the n: ");
    scanf("%d", &n);

    for( i = 1; i <= n; i++)
    {
        for(j = n - 1; j >= i; j--)
        {
            printf(" ");
        }
        for(k = 1; k <= m; k++)
        {
            printf("*");
        }
        m = m + 2;
        printf("\n");
    }
}