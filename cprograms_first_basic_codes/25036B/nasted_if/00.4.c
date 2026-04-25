# include <stdio.h>

int main()
{
    int n1, n2, n3;
    printf("Enter the numbers: ");
    scanf("%d%d%d", &n1, &n2, &n3);

    int lag;

    if (n1 > n2 && n1 >n3)
    {
        lag = n1;
    }
    else if (n2 > n3)
    {
        lag = n2;
    }
    else
    {
        lag = n3;
    }
    printf("largest number is %d\n", lag);
    return 0;
}