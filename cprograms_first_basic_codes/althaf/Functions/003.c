/*WAP to generate the prime series upto the given limit using functions
    sample input:- 10
    sample output:-2 3 5 7*/


#include <stdio.h>
void generate_prime(int);
int is_prime(int);

int main()
{
    int limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);

    if(limit > 1)
    {
        generate_prime(limit);
    }
    else
    {
        printf("Given input is INVALID.\n");
    }
    return 0;
}
void generate_prime(int limit)
{
    printf("RES: ---> ");
    for(int num = 2; num <= limit; num++)
    {
        if(is_prime(num) != 0)
        {
            printf("%d ", num);
        }
    }
    printf("\n");
}


int is_prime(int num)
{
    if(num < 2)
    {
        return 0;
    }
    for(int i = 2; i * i <= num; i++)
    {
        if(num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
