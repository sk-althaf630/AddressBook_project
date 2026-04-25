/*WAP to check if a number is perfect or not by loops   what is perfect number if number is proper divisoe sum (lik  6  1, 2, 3 are positive divisors it sum = 6)
    sample input:- limit --6
    sample output:- 1 + 2 + 3 = 6 it is a perfect number*/

#include <stdio.h>
int main()
{
    int limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);

    int sum = 0;
    for(int i = 1;i <= limit/2; i++)
    {
        if(limit % i ==0)
        {
            sum = sum + i;
        }
    }
    printf("\n");

    if(limit == sum)
    {
        printf("%d Yes, it a perfect number.\n", limit);
    }
    else
    {
        printf("%d No, it not a perfect number.\n", limit);
    }
    return 0;
}
