#include <stdio.h>
char *my_str(char *s)
{
    char *start = s;
    while(*s)
    {
        if(*s >= 'A' && *s <= 'Z')
        {
            *s = *s + 32;
        }
        if(*s >= 'a' && *s <= 'z')
        {
            *s = *s - 32;
        }

        s++;
    }
    return start;
}
int main()
{
    char str[100];
    char *ret;
    printf("Enter the words: ");
    scanf("%[^\n]", str);

     ret = my_str(str);
    printf("After --> %s\n", ret);
}