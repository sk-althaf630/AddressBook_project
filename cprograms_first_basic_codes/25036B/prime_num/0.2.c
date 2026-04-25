#include <stdio.h>
int main()
{
    int n1, n2, i, j;
    int count;
    printf("Enter the first number: ");
    scanf("%d", &n1);
    printf("Enter the second number: ");
    scanf("%d", &n2);

    printf("The prime numbers between %d and %d are:\n", n1, n2);


    for(i = n1 ;  i <= n2; i++)
    {  
        count = 0;
        for(j = 2; j * j <= i; j++)
        {
         if(i % j ==0)
         {
           count = 1;
           break;
         }
        }
        if(count == 0)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;

}