//finding the length of the a string
#include <stdio.h>
int my_strlen(char *ptr)
{
    int len =0;
    while(ptr[len] != '\0')
    {
        len++;
    }
    return len;
}
int main()
{
    char str[100];
    printf("Enter the string: ");
    scanf("%[^\n]", str);

    int count = my_strlen(str);
    printf("length = %d\n", count);
    return 0;
}