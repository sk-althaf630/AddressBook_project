#include <stdio.h>
int getword(char *ptr)
{
    int len = 0;
    while(*ptr !='\0')
    {
        if(*ptr != ' ')
        {
            len++;
        }
        ptr++;
    }
    return len;
}
int main()
{
    char str[100];
    printf("Enter the string: ");
    scanf("%s", str);

    int len = getword(str);
    printf("%s --> %d\n", str, len);

}
