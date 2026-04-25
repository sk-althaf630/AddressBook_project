/* WAP to check if the number is in range or not like 0 to 100.
sample input :- 45 0 100
sample output :- 45 is within the range of 0 to 100. */
#include <stdio.h>

int main() 
{
    int num, lower, upper;
    printf("Enter number, lower bound, and upper bound: ");
    scanf("%d %d %d", &num, &lower, &upper);

    if(num >= lower && num <= upper) 
    {
        printf("%d is within the range of %d to %d.\n", num, lower, upper);
    } 
    else 
    {
        printf("%d is OUTSIDE the range of %d to %d.\n", num, lower, upper);
    }
    return 0;
}