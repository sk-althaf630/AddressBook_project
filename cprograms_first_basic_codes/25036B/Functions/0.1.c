#include <stdio.h>
int mod(int n);//declaration of function

int main()
{
    int num;
    printf("enter num: ");
    scanf("%d", &num);

    int res = mod(num);//call of function
    printf("Res is %d\n", res);

    return 0;
}

int mod(int n)//definition of funtion
{
    n = n +5;
    return n;
}