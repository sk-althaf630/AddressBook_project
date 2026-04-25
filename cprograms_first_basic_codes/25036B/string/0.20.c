#include <stdio.h>
char *my_strchr(char *ptr, char ch)
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
    
    char *ptr = my_strchr(str,ch);
    if(ptr == NULL)
    {
        printf("charactor not pressent\n");
        return 1;
    }
    printf("Res: %s\n", ptr);
}