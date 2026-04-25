#include <stdio.h>
void resve(char *str, int l)
{
    static int i = 0;
    if(i >= l)
    {
        return;
    }
        char temp = str[i];
        str[i] = str[l];
        str[l] = temp;
        i++;
     resve(str,l-1);
}
int main()
{
    char str[100];
    printf("enter the str: ");
    scanf("%[^\n]", str);
    int len = 0;
    while(str[len])
    {
        len++;
    }

    resve(str,len-2);
    printf("REs: --> %s\n", str);
}