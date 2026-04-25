//WAP to count the number of vowels in the string.
// vowels --> A, E, I, O, U
// sample input :- hello world
// sample output :-  vowels-> 3

#include <stdio.h>
int my_vol(char *n)
{
    int len = 0;
    while(*n !='\0')
    {
        if(*n== 'a'|| *n == 'e' || *n =='i' || *n == 'o' || *n == 'u' || *n == 'A'|| *n == 'E' || *n =='I' || *n =='O' || *n =='U')
        {
            len++;
        }

        n++;
    }
    return len;
}
int main()
{
    char str[100];
    printf("enter the words: ");
    scanf("%[^\n]", str);

    int ret = my_vol(str);
    printf("The vowle count --> %d\n", ret);
}