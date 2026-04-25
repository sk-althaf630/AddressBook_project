#include <stdio.h>//prime  number
int main()
{
    int i, n, count = 1;
    printf("Enter the number");
    scanf("%d", &n);
 
    for(i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            count = 0;
            break;
        }
    }
    if(count)
    {
        printf("prime");
    }
    else
    {
        printf("Not prime");
    }
}