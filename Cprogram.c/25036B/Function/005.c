#include <stdio.h>
int multi(int, int);
int main()
{
    int num1, num2, res;
    printf("enter the nums: ");
    scanf("%d%d", &num1, &num2);

    res = multi(num1,num2);
    printf("Res: %d\n", res);
    return 0;
}
int multi(int num1, int num2)
{
    return num1 * num2;
}