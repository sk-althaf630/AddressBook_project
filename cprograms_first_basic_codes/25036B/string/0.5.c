#include <stdio.h>

int my_strlen(char *s)
{
    int len = 0;
    while(*s !='\0')
    {
        len++;
        s++;
    }
    return len;
}

int main()
{
    char str[100];
    printf("enter the string: ");
    scanf("%s", str);

    int len = my_strlen(str);
    printf("%d\n", len);
}