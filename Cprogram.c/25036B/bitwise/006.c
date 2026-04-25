/*Clear 1st set bit from LSB.
sample intput:- 10
sample output: Before Clear 1st set bit form LSB is : 10
                    00000000 000000000 00000000 00001010
                After Clear 1st set bit form LSB is : 8
                    00000000 00000000 00000000 00001000*/
#include <stdio.h>

int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);

    printf("Before Clear 1st set bit form LSB is : %d\n", num);
    for(int i = 31; i >= 0; i--)
    {
        if(num & (1 << i))
        {
            printf("1 ");
        }
        else
        {
            printf("0 ");
        }
    }
    printf("\n");

    int result = num & (num - 1);
    printf("After Clear 1st set bit form LSB is : %d\n", result);
    for(int i = 31; i >= 0; i--)
    {
        if(result & (1 << i))
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