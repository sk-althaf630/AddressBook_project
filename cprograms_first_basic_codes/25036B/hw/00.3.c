/*Description:-
     Date:-13 oct 25
     Time:-6h
     Code Name:-Division of 2 variable
                        */

#include <stdio.h>

int main()
{
    float num1, num2;

    printf("Enter the numbers: ");
    scanf("%f%f", &num1, &num2);

    float division = num1 / num2;

    printf("Answer is %f\n", division);
    return 0;
}