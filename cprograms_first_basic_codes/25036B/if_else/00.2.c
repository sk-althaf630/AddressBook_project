#include <stdio.h>
int main ()
{
    int num;


    printf( "Enter the number: ");
    scanf("%d", &num);

    if (num > 2)
    {
        printf("Yes, number is greater then 2\n");
        
    }
    else
    {
        printf("No, number is less then 2\n");

    }

    printf("Ending\n");
}