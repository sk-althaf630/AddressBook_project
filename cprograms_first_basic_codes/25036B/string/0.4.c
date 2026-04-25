#include <stdio.h>
void fun(char *cptr)
{
    printf("%s\n", cptr);
}
int main()
{
    char str[100];

    printf("enter the string: ");
    scanf("%[^\n]", str);

    fun(str);
    //printf("res: %s"str);
}
