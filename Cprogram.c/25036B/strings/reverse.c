//WAP to reverse the string.
// sample input :- hello
// sample output:- olleh
#include <stdio.h>
void reve_str(char *);

int main()
{
    char str[100];
    printf("Enter the string : ");
    scanf("%[^\n]", str);

    reve_str(str);

    printf("The reverse the string is %s\n", str);
    return 0;
}

void reve_str(char *ptr)
{
    int len = 0;
    while(ptr[len] != '\0')
    {
        len++;
    }

    for(int i = 0; i < len/2; i++)
    {
        char temp = ptr[i];
        ptr[i] = ptr[len - 1 - i];
        ptr[len - 1 - i] = temp;
    }
}