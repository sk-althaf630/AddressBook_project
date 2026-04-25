//this strcpy will coy the string source to destony
#include <stdio.h>
char *my_strcpy(char *d, char *s)
{
    int i = 0;
    while(s[i] != '\0')
    {
        d[i] = s[i];
        i++;
    }
    d[i] = '\0';
    return d;
}
int main()
{
    char sourc[100];
    printf("Enter the string: ");
    scanf("%s", sourc);

    char destony[100];
    my_strcpy(destony,sourc);
    printf("string is copyed in to destony: %s\n", destony);
    return 0;
}