#include <stdio.h>
int main()
{
    float amount, rate, time, simple_interest;
    printf("Enter the Principal amount: ");
    scanf("%g", &amount);
    printf("Enter the Annul rate of interest: ");
    scanf("%g", &rate);
    printf("Enter the Time period: ");
    scanf("%g", &time);

    simple_interest = (amount*rate*time)/100;
    printf("Answer is: %g\n", simple_interest);\
    
    return 0;
}