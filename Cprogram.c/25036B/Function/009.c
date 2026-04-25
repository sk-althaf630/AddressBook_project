#include <stdio.h>
void add(int num1, int num2)
{
    printf("addition: %d", num1 + num2);
}
void sub(int num1, int num2)
{
    printf("subtraction: %d", num1 - num2);
}

void mult(int num1, int num2)
{
    printf("multipcation: %d", num1 * num2);
}

void divi(int num1, int num2)
{
    if(num2 > 0)
    {
       printf("divition: %g", (float)num1 / num2);
    }
    else
    {
        printf("ERROR\n");
    }
}

int main()
{
    int num1,num2;
    char ch;
    printf("Enter the num1 and num2: ");
    scanf("%d %c %d", &num1, &ch, &num2);

    switch(ch)
    {
        case '+':
        add(num1,num2);

        case '-':
        sub(num1,num2);

        case '*':
        mult(num1,num2);

        case '/':
        divi(num1,num2);
    }
}