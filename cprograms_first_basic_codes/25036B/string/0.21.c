#include <stdio.h>
char *my_strrchr(char *ptr, char ch)
{
    int len = my_strchr(ptr);

    while(len > 0)
    {
        if(len - 1 == ch)
        {
            return  ptr;
        }
        len--;
    }
    return NULL;
}
char *my_strchr(char *ptr, char *ch)
{
    while(*ptr)
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
    printf("enter: ");
    scanf("%[^\n]", str);

    char ch;
    printf("find that: ");
    scanf(" %c", &ch);
    
    char *ptr = my_strrchr(str,ch);
    if(ptr == NULL)
    {
        printf("charactor not pressent\n");
        return 1;
    }
    printf("Res: %s\n", ptr);
}