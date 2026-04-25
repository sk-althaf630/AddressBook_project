#include <stdio.h>
int main()
{
    int n1, n2, n3, midd;
    printf("Enter the number: ");
    scanf("%d%d%d", &n1, &n2, &n3);

    if (n1 < n2 )
    {
        if (n2 < n3)
        {
            midd = n2;
            printf("%d is middle\n", midd);
        }
        else if (n1 < n3)
        {
            midd = n3;
            printf( "%d is middle\n", midd);
        }
        else
        {
            midd = n1;
            printf("%d is the middle\n", midd);
        }
    }
    else
    {
        if (n1 < n3)
        {
            midd = n1;
            printf("%d is middle\n", midd);
        }
        else if (n2 < n3)
        {
            midd = n3;
            printf("%d is middle\n", midd);
        }
        else
        {
            midd = n2;
            printf("%d is middle\n", midd);
        }
    }
}    