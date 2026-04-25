/*wap to check the number is prime or not
    sample input:- 2 and 4
    sample output:-prime and not prime*/


#include <stdio.h>
int prime(int n);

int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);

    if(num < 2)
    {
        printf("It should be greater then 2...");
        return 1;
    }

    int ret = prime(num);
    if(ret != 0)
    {
        printf("Entered number is not a prime...\n");
    }
    else
    {
        printf("Entered number is a prime...\n");
    }
    return 0;
}

int prime(int n)
{
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            return 1;
        }
    }
    return 0;
}