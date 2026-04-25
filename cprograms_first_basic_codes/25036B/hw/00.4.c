/*Description:-
     Date:-13 oct 25
     Time:-6:40
     Code Name:-percentage of 2 variable
                        */

#include <stdio.h>

int main()
{
    float num1, num2;

    printf("Enter the numbers: ");
    scanf("%f%f", &num1, &num2);

    float percentage = (num1 / num2) * 100;
    printf("Answer is %f\n", percentage);

    return 0;
}