/*this is manule working of strchr bilten function, In this it checke given ch is present in str
sample input :- str -> hello world and ch -> l
sample output:- returns -> llo world*/

#include <stdio.h>
char *my_strchr(char *ptr, char ch)
{
    while(*ptr != '\0')
    {
        if(*ptr == ch)
        {
            return ptr;
        }
        ptr++;
    }
    return NULL;
}
int main()
{
    char str[100];
    printf("Enter the string: ");
    scanf("%[^\n]", str);

    char ch;
    printf("Enter the charactor to find in string: ");
    scanf(" %c", &ch);

    char *ret = my_strchr(str,ch);
    if(ret == NULL)
    {
        printf("charactor not found in string\n");
        return 1;
    }
    printf("ret = %s\n", ret);
    return 0;
}