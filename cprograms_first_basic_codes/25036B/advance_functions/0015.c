//wap to without using switch case statemen do this operation
#include <stdio.h>

void add(int a, int b)
{
    printf("sum = %d\n", a + b);
}

void sub(int a, int b)
{
    printf("sub = %d\n", a - b);
}

void mult(int a, int b)
{
    printf("Mult = %d\n", a * b);
}

void divi(int a, int b)
{
    if(b != 0)
    {
    printf("divi = %d\n", a/b);
    }
    else
    {
        printf("Error: Division by zero!\n");
    }
}
int main()
{
    int choice, a, b;
    void (*fptr[10])(int, int) = {add, sub, mult, divi};

    printf("Enter the values: ");
    scanf("%d %d", &a, &b);

    printf("Enter the choice(0= add, 1= sub, 2= multp, 3= divi): ");
    scanf("%d", &choice);

    if(choice >= 0 && choice < 4)
    {
        (*fptr[choice])(a,b);
    }
    else
    {
        printf("Invvalid choice!\n");
    }
    return 0;
}