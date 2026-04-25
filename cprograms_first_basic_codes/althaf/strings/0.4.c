/* copy arr1 to arr2  using functions 
   sample:- hello
   sample output:-1 --> hello
                   2 ---> hello*/

#include <stdio.h>
char fun(char *s, char *e)
{
    while(*s != '\0')
    {
        *e = *s;
        
        s = s + 1;
        e = e + 1;
    }
    return *e;
}

int main()
{
    char source[100];
    char desteny[100];
    printf("Enter: ---> ");
    scanf("%[^\n]", source);

    printf("Before: ---> %s\n", source);

    fun(source,desteny);
    printf("After: ---> %s\n", desteny);

}