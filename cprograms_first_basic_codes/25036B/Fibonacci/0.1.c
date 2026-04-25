#include <stdio.h>//+ve
int main()
{
    int num,next = 0,first = 0, second = 1;
    printf("enter the numbers: ");
    scanf("%d", &num);
    
    while(next <= num)
    {
        printf("%d ", next);
        first = second;
        second = next;
        next = first + second;
    }
    
    if(num < 0)
    {
        printf("invalid\n");
    }
    return 0;
}