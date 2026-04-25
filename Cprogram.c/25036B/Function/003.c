#include <stdio.h>
int add(int, int);
int main()
{
    int num1, num2;
    printf("enter nums: ");
    scanf("%d%d", &num1, &num2);

    int res = add(num1,num2);
    printf("sum of numbers: %d\n", res);
    return 0;
}
int add(int num1, int num2)
{
    return num1 + num2;
}