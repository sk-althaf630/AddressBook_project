





#include <stdio.h>
int my_strcmp(char *s, char *s2)
{
    int i = 0;
    while(s[i] !='\0' && s2[i] != '\0')
    {
        if(s[i] != s2[i])
        {
            return s[i] - s2[i];
        }
        i++;
    }
    return s[i] - s2[i];
}
int main()
{
    char str1[100];
    char str2[100];
    printf("enter the 1: ");
    scanf("%[^\n]", str1);

    printf("enter the 1: ");
    scanf(" %[^\n]", str2);

    int res = my_strcmp(str1,str2);
    if(res < 0)
    {
        printf("str1 < str2\n");
    }
    else if(res > 0)
    {
        printf("str1 > str2\n");
        
    }
    else
    {
        printf("str1 == str2\n");
    }

}