#include <stdio.h>
int main()
{
    int num;
    printf("enter the limit:");
    scanf("%d", &num);
    int rem;
    int rev=0;

    while (num > 0)
    {
        rem = num % 10;
        rev =rev*10+ rem;
        num =num/10;
    }
    printf("Revers number is %d\n", rev);

    
    return 0;
    
}