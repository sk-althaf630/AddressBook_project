//volatile
#include<stdio.h>
/*int main()
{
    volatile unsigned int wait = 0xFFFFFFFF;
    char bit = 0;
    while(1)
    {
        if(!wait--)//non-blocking delay
        {
            printf("The bit is now %d\r", bit);
            bit=!bit;
            fflush(stdout);
            //for(wait = 0xFFFFFFFF;wait--;);//blocking delay
            wait = 0xFFFFFFFF;
        }
    }
}*/

/*int main()
{
    volatile unsigned int i;
    int num;
    for(i = 0; i < 0xFFFFFFFF; i++)
    {
        num = 53;
    }
    printf("%d\n", num);
}*/

int main()
{
    int num1;
    volatile int num2 = 1;
    num1 = ++num2 + num2++ + num2++ + num2++;
    printf("%d\n", num1);
    return 0;
}