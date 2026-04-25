/*Print binary of given integer.*/

#include <stdio.h>

int main()
{
    int num;
    printf("Enter the number : ");
    scanf("%d", &num);

    for(int i = 31; i >= 0; i--)
    {
        if(num & (1<<i))
        {
            printf("1 ");
        }
        else
        {
            printf("0 ");
        }
    }

    return 0;
}