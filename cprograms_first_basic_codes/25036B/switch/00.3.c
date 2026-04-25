#include <stdio.h>
int main()
{
    char ch;
    int num1, num2;

    printf("which operation you want to perform: \nfor addition press '+'\nfor subration press '-'\nfor multipulication press '*'\nfor division press '/'\n");
    scanf("%c", &ch);

    printf("Enter the numbers: ");
    scanf("%d%d", &num1, &num2);

    if (num2 == 0 && ch == '/')
    {
        printf("You cannot divide a number with zero\n");
        return 100;
    }
    switch(ch)
    {
        case '+':
        printf("Addition of %d\n", num1 + num2);
        break;

        case '-':
        printf("Subtraction of %d\n", num1 - num2);
        break;

        case '*':
        printf("Multipulication of %d\n", num1 * num2);
        break;

        case '/':
        printf("Division of %g\n", (float)num1 / num2);
        break;
        default:
        printf("Press the correct operation\n");


    }
}