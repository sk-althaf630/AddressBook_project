/*WAP to check a number is prime or not
    sample input:- 4
    sample output:- not prime*/



#include <stdio.h>
int main()
{
    int num ,i;
    int count = 0;
    printf("Enter the number: ");
    scanf("%d", &num);

    for(i = 2; i * i <= num; i++)
    {
        if(num % i ==0)
        {
            count = 1;
            break;
        }
    }
    if(count == 1)
    {
        printf("%d is a not prime\n", num);
    }
    else
    {
        printf("%d is a prime\n", num);
    }
}