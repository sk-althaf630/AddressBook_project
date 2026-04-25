#include <stdio.h>
void add(int, int);
void sub(int, int);
void mult(int, int);
void divi(int, int);

int main()
{
    char ch;
    int num1, num2;
    printf("enter the number:");
    scanf("%d %c %d", &num1, &ch, &num2);

    switch(ch)
    {
        case '+':
        add(num1,num2);
        break;

        case '-':
        sub(num1,num2);
        break;

        case '*':
        mult(num1,num2);
        break;

        case '/':
        divi(num1,num2);
        break;

        default:
        printf("invalid\n");
    }
    
return 0;
}

void add(int num1, int num2)
{
    printf("addition: %d\n", num1 + num2);
}
void sub(int num1, int num2)
{
    printf("substraion: %d\n", num1 - num2);
}
void mult(int num1, int num2)
{
    printf("Multiplication: %d\n", num1 * num2);
}
void divi(int num1, int num2)
{
    if(num2 != 0){
    printf("Divition: %g\n", (float)num1 / num2);
    }
    else
    {
        printf("Error: Division by zero is not allowed.\n");
    }
}