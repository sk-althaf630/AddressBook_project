#include <stdio.h>
int my_digit(char *n)
{
    int len = 0;
    while(*n !='\0')
    {
        if(*n >= '0' && *n <= '9')
        {
            len++;
        }

        *n++;
    }
    return len;
}
int main()
{
    char str[100];
    printf("enter the words: ");
    scanf("%s", str);

    int ret = my_digit(str);
    printf("%d\n", ret);
}