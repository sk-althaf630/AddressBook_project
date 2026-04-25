#include <stdio.h>

int main()
{
    int ph;
    printf("Enter the number: ");
    scanf("%d", &ph);

    if (ph == 100)
    {
        printf("Battery is Full\n");

    }
    else if (ph <=10)
    {
        printf("Lower Battery\n");

    }
     else if (ph > 100)
     {
        printf("DONT CHARGE\n");

     }
     else 
     {
        printf("Keep on chargeing\n");
     }
     printf("programe is over\n");
      
     return 0;
}