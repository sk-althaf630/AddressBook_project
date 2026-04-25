/* count the character present in the world use function
   sample:- hello
   sample output:-5*/

 #include <stdio.h>
 int my_strlen(char *c)
 {
    int len = 0;
    while(*c !='\0')
    {
        len++;
        c++;
    }
    return len;
 }
int main()
{
    char str[100];
    printf("Enter her: --> ");
    scanf("%[^\n]", str);

    int ret = my_strlen(str);
    printf("Count: --> %d", ret);
}