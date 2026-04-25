#include <stdio.h>
int main()
{
    int limit;
    int i = limit;
    printf("Enter the limits: ");
    scanf("%d", &limit);

    do
    {
        printf("%d ", i);
        i--;
    }while(i >= 1);
    printf("\n");
    return 0;
}