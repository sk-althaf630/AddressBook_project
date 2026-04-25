/* count the words use function
   sample:- hello man how are you
   sample output:-5*/
#include <stdio.h>
int my_count(char *cn)
{
    int len = 0;
    while(*cn !='\0')
    {
        if(*cn == ' ')
        {
            len++;
        }
        cn++;
    }
    return len + 1;
}
int main()
{
    char str[100];
    printf("Enter: ---> ");
    scanf("%[^\n]", str);

    int ret = my_count(str);
    printf("Count: ---> %d\n", ret);
}
