#include <stdio.h>
void my_strcpy(char *d, char *s)
{
    int i = 0;
    while(s[i] !='\0')
    {
        d[i] = s[i];
        i++;

    }
    d[i] = '\0';
}
int main()
{
    char source[100];
    char dest[100];

    printf("enter the words: ");
    scanf("%s", source);

    my_strcpy(dest,source);
    printf("%s\n", dest);
}