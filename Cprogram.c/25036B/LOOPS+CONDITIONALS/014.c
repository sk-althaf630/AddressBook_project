/* WAP to check if a year is leap or not.
sample input :- 2024
sample output :- 2024 is a leap year. */
#include <stdio.h>

int main() 
{
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);

    if ( (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) 
    {
        printf("%d is a leap year.\n", year);
    } 
    else 
    {
        printf("%d is not a leap year.\n", year);
    }
    return 0;
}