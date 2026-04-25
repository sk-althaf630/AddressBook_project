/* count the words use function
   sample:- hello man how are you
   sample output:-5*/
 
#include <stdio.h>
int my_count(char *s1, char *s2)
{
    int i = 0;
    while(s1[i] !='\0' && s2[i] !='\0')
    {
        if(s1[i] != s2[i])
        {
            return s1[i] - s2[i];
        }
        i++;
    }
    return s1[i] - s2[i];
}
int main()
{
    char str1[100];
    char str2[100];

    printf("Enter: ----> ");
    scanf("%[^\n]", str1);

    printf("Enter2: ----> ");
    scanf(" %[^\n]", str2);

    int ret = my_count(str1,str2);
    printf("Count: ----> %d\n", ret);

    if(ret > 0)
    {
        printf("str1 is greater.\n");
    }
    else if(ret < 0)
    {
        printf("str2 is greater.\n");
    }
    else
    {
        printf("str1 and str2 is equal.\n");
    }
}