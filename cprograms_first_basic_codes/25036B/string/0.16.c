#include <stdio.h>
void resve(char *str)
{
    int len = 0;
    while(str[len])
    {
        len++;
    }
    for(int i = 0; i < len/2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}
int main()
{
    char str[100];
    printf("enter the str: ");
    scanf("%[^\n]", str);

    resve(str);
    printf("REs: --> %s\n", str);
}