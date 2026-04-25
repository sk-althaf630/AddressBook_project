//this string will cmper two string and return small -> -ve, large -> +ve, and equal -> 0
#include <stdio.h>
int my_strcmp(char *ptr1, char *ptr2)
{
    int i = 0;
    while (ptr1[i]  != '\0' && ptr2[i] != '\0')
    {
        if(ptr1[i] != ptr2[i])
        {
            return ptr1[i] - ptr2[i];
        }
        i++;
    }
    return ptr1[i] - ptr2[i];
}
int main()
{
    char str1[100];
    printf("Enter the first string: ");
    scanf("%s", str1);

    char str2[100];
    printf("Enter the second string: ");
    scanf(" %[^\n]", str2);

    int ret = my_strcmp(str1,str2);
    if(ret == 0)
    {
        printf("strings are equal\n");
    }
    else if(ret > 0)
    {
        printf("string 1 is greterthen(>) string 2\n");
    }
    else
    {
        printf("srting 1 is lesserthen(<) string 2\n");
    }
    return 0;
}