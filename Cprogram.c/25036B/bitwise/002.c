/*Check number is even/odd.
sample input :- 2
sample output:- The number 2 is even*/

#include <stdio.h>
int main()
{
    int num;
    printf("Enter the number : ");
    scanf("%d", &num);

    // Check the least significant bit
    if(num & 1)  
    {
        // If LSB is 1 → odd number
        printf("The number %d is odd\n", num);
    }
    else
    {
        // If LSB is 0 → even number
        printf("The number %d is even\n", num);
    }

    return 0;
}