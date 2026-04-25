#include <stdio.h>
#include <maths.h>
int main()
{
    int i, j, num;
    printf("enter the num: ");
    scanf("%d", &num);

    for(i = 1; i <= num; i++)
    {
        for(j = 1;j <= abs(i); j++)
        {
            printf("*");
        }
        printf("\n");
    }
}