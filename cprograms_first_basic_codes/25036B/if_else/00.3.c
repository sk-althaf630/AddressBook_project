#include <stdio.h>
int main ()
{
    int amount;


    printf( "Enter the number: ");
    scanf("%d", &amount);

    if (amount >= 99)
    {
        printf("----Wellcome to namma metro----\n");
        
    }
    else
    {
        printf("no amount in card\n");

    }

    printf("Ending\n");
}