# include <stdio.h>
int main()
{
    int n1, n2, n3, midd;
    scanf("%d%d%d", &n1, &n2, &n3);
    if(n1 > n2 && n1 > n3)||(n1 < n2 && n1 < n3)
    {
        midd = n1;
    }
    else if (n2 > n3 && n2 > n1)||(n2 < n3 && n2 < n1)
    {
        midd = n2;
    }
    else
    {
        midd = n3;
    }
    printf("%d is middle: %d\n", midd);

    return 0;
}