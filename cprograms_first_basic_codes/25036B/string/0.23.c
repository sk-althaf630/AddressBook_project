//to find substring
#include<stdio.h>

char *my_strstr(char *str, char *sub_str);

int main()
{
    char str[100];
    printf("Enter the string:");
    scanf("%[^\n]", str);

    char sub_str[100];
    printf("enter the sub_string:");
    scanf(" %[^\n]", sub_str);

    char *ptr=my_strstr(str, sub_str);
    if(ptr == NULL)
    {
        printf("Character is not present\n");
        return 0;
    }
    
    printf("%s\n", ptr);
    return 0;    
}    

char *my_strstr(char *str, char *sub_str)
{
    char *s, *p;
    while(*str)
    {
        s=str;
        p=sub_str;
        while(*s && *p && (*s == *p))
        {
            s++;
            p++;
        }
        
        if(*p == '\0')
            return str;
            
        str++;
    }
    return NULL;
}