#include <stdio.h>
void reverse(char *s, char *e)
{
    while(s < e)
    {
        char temp = *s;
        *s = *e;
        *e = temp;
        s++;
        e--;
    }
}
void rever_world(char *n)
{
    char *temp = n;
    while(*n)
    {
        if(*n == ' ')
        {
            reverse(temp,n - 1);
            temp = n + 1;
        }
        n++;
    }
   reverse(temp,n - 1);
    
}
int main()
{
    char str[100];
    printf("enter the str: ");
    scanf("%[^\n]", str);

    rever_world(str);
    printf("RES --> %s\n", str);

}