#include <stdio.h>
char *my_strstr(char *ptr1, char *ptr2)
{
    if(*ptr2 == '\0')
    {
        return ptr1;
    }

    while(*ptr1 != '\0')
    {
        char *main = ptr1;
        char *sub = ptr2;
        while(*main != '\0' && *sub != '\0' && (*main == *sub))
        {
            main++;
            sub++;
        }

        if(*sub == '\0')
        {
            return ptr1;
        }
        ptr1++;
    }
    
    return NULL;
}
int main()
{
    char main_str[100];
    printf("Enter the main string : ");
    scanf("%[^\n]", main_str);

    char sub_str[100];
    printf("Enter the sub string : ");
    scanf(" %[^\n]", sub_str);

    char *ptr = my_strstr(main_str,sub_str);

    if(ptr == NULL)
    {
        printf("sub_string is not in main_string\n");
    }
    else
    {
        printf("%s ---> is there in main_string\n", ptr);
    }
    return 0;
}