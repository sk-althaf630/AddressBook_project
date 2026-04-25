#include <stdio.h>
int main()
{
    int n1 = 40, n2 = 30;
    int lar;

    n1>n2 ? (lar = n1) : (lar = n2);

    printf("largest value is %d\n", lar);

    return 0;
}