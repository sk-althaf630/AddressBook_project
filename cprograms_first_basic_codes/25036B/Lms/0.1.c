#include <stdio.h>
int main()
{
    int fahrenheit;
    float celsius;

    printf("Enter the fahrenheit: \n");
    scanf("%d", &fahrenheit);

    celsius = (fahrenheit - 32)*5/9;
    printf("Answer is: %g\n", celsius);

    return 0;
}