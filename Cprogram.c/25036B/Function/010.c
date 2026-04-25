#include <stdio.h>
int is_prime(int num)
{
    if (num < 2)
    {
        return 0;
    }
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
void generate_prime(int limit)
{
    for (int i = 2; i <= limit; i++)
    {
        if (is_prime(i) != 0)
        {
            printf("%d", i);
        }
    }
    printf("\n");
}
int main()
{
    int limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);

    if (limit > 1)
    {
        generate_prime(limit);
    }
    else
    {
        printf("ERROR : INVALID....");
    }
    return 0;
}