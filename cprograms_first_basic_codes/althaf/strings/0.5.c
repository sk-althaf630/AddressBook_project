/* count the character present in the world use function
   sample:- hello
   sample output:-5*/

#include <stdio.h>
int my_count(char *s)
{
    int len = 0;
    while(*s !='\0')
    {
        if(*s >= 'a' && *s <= 'z' || *s >= 'A' && *s <= 'Z' || *s >= '0' && *s <= '9')
        {
            len++;
        }
        *s++;
    }
    return len;
}
int main()
{
    char str[100];
    printf("Enter: --> ");
    scanf("%[^\n]", str);

    int ret = my_count(str);
    printf("Count: ---> %d\n", ret);
}