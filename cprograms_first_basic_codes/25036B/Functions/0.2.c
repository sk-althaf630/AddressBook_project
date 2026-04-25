#include <stdio.h>
int mod(int n)//without declaration
{
    n = n +5;
    return n;
}

int main()
{
    int num;
    printf("enter num: ");
    scanf("%d", &num);

    int res = mod(num);//call of funtion
    printf("Res is %d\n", res);

    return 0;
}
