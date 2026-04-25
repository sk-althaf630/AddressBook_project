#include <stdio.h>
//#warning is just for printing our own custam made warning massage it will not effect on outputpr
#if defined DEBUG_PRINT//it checks if the argument is all readey defined are not if not meanes it well not incloud this massage
#warning "Debug print enabled"
#endif
int main()
{
    int num1, num2;
    printf("Enter two number :");
    scanf("%d %d", &num1, &num2);

    printf("The two number are %d %d\n", num1, num2);
    #if defined DEBUG_PRINT
    printf("sum = %d\n", num1+num2);
    #endif
    printf("multp = %d\n", num1 *num2);
}