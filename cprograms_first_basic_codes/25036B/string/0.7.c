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

        *n++;
    }
    return len;
}
int main()
{
    char str[100];
    printf("enter the words: ");
    scanf("%s", str);

    int ret = my_vol(str);
    printf("%d\n", ret);
}