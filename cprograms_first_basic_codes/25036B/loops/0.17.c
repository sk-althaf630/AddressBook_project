#include <stdio.h>
int main()
{
    int limit, i = 0, sum = 0;
    printf("Enter the limit:");
    scanf("%d", &limit);

    do
    {
       printf("%d ", i);
       sum += i;
       i++; 
    }while(i <= limit);
    printf("\n");
    printf("The sum of the %d numbers: %d\n", limit, sum);
    return 0;
}