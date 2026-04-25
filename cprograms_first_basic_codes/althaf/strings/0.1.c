/* print a sentens and replace with a letter 
   sample:- hello
   sample output:-hella*/

#include <stdio.h>
int main()
{
    char str[100];
    printf("Enter the words: ");
    scanf("%s", str);

    printf("Before: ---> %s\n", str);
    str[4] = 'B';
    printf("After: ---> %s\n", str);
}