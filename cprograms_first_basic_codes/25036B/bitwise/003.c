#include <stdio.h>
int main()
{
    int num, count = 0;
    printf("enter number: ");
    scanf("%d", &num);
    for(int i = 0; i < 32; i++)
    {
        if(num &(1 << i))
        {
            count++;
        }
    }
    printf("the no of set bits in %d are %d\n", num, count);
}