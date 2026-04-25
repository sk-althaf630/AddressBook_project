#include <stdio.h>
int my_digit(char *n)
{
    int len = 0;
    while(*n !='\0')
    {
        if(*n >= 'a' && *n <= 'z' || *n >= 'A' && *n <= 'Z')
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