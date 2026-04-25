#include <stdio.h>
float avg(int n1, int n2, int n3)
{
    return(float)(n1+n2+n3)/3;
}
int main()
{
    int num1, num2, num3;
    printf("enter the nums:");
    scanf("%d%d%d", &num1, &num2, &num3);

    float res = avg(num1,num2,num3);
    printf("Res: %g\n", res);
}