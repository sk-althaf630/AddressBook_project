#include <stdio.h>
int prime(int);

int main()
{
    int num;
    printf("enter the num: ");
    scanf("%d", &num);

    if(num < 2)
    {
        printf("It should be greater then 1\n");
        return 1;
    }
   int res = prime(num);
   if(res)
   {
    printf("%d is not prime\n", num);
   }
   else{
    printf("%d is prime\n", num);
    
   }
   return 0;
}
int prime(int num)
{
    for(int i = 2; i * i <= num;i++)
    {
        if(num % i == 0)
        {
            return 1;
        }
    }
    return 0;
}