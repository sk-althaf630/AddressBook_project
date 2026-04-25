#include <stdio.h>
int main()
{
    int num, i;
    int count = 0;

    printf("enter the number: ");
    scanf("%d", &num);

    for(i = 2; i * i <= num; i++)
    {
        if(num % i ==0)
        {
            count = 1;
            break;
        }
    }
    if(count == 0)
    {
       printf("%d is prime number\n", num);
    }
    else//count == 1
    {
        printf("%d is  not prime number\n", num);
    }
    
}