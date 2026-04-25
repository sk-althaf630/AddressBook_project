/* print a sentens and replace with a letter using functions 
   sample:- hello
   sample output:-hella*/


#include <stdio.h>
void fun(char *cptr)
{
    printf("It is her: %s\n", cptr);
}
int main()
{
    char str[100];
    printf("Enter her: ");
    scanf("%[^\n]", str);

    fun(str);
}