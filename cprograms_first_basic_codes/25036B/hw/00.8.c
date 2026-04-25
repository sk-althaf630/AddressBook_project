#include <stdio.h>
int main()
{
   int limit,i;
   int count = 1;
   printf("enter the number: ");
   scanf("%d", &limit);

   if(limit <= 1)
   {
    count = 0;
   }
   else
   {
   
     for(i = 2; i * i <= limit /2; i++)
     {
      if(limit % i == 0)
     {
        count = 0;
        break;
      }
     }
    }
    if(count == 1)
    {
        printf("prime\n");
    }
    else
    {
        printf("Not prime\n");
    }
   return 0;
}