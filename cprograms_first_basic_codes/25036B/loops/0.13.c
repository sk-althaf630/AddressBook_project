#include <stdio.h>
int main()
{
    int n1, n2;
    printf("Enter the number:");
    scanf("%d%d", &n1, &n2);

    int i, sum=0;
    for(i=0;i<n1;i++)
    {
        sum=sum+n2;
    }
    printf("%d ", sum);
}