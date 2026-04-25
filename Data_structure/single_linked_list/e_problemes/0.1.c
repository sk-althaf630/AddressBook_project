#include<stdio.h>
int main()
{
    long  int n1, n2;
    printf("Enter the numbers: ");
    scanf("%ld%ld", &n1, &n2);

    long  int mul = n1*n2;

    printf("%ld\n", mul);

    return 0;
}