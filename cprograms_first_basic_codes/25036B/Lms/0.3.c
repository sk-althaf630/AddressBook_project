#include <stdio.h>
int main()
{
    float amount, rate, time, simple_interest;

    printf("-----Simple interest Calculator------\n");

    printf("Enter the Principal amount(P): ");
    scanf("%f", &amount);
    printf("Enter the Annul rate of interest(R, in %%): ");
    scanf("%f", &rate);
    printf("Enter the Time periodm(in years): ");
    scanf("%f", &time);

    simple_interest = (amount*rate*time)/100;
    printf("\n---Result---\n");
    printf("Principal: $%.2f\n", amount);
    printf("Rate: %.2f%%\n", rate);
    printf("Time: %.2f year\n", time);
    printf("-----------\n");
    printf("Answer is: $%.2f\n", simple_interest);
    
    return 0;
}