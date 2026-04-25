//WAP to reverse each word of the string at their fixed place.
// sample input :- hello world
// sample output :- olleh dlrow
#include <stdio.h>
#include <string.h>

void reves(char *str, int start, int end)
{
    while(start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    char str[100];
    printf("Enter the string: ");
    scanf("%[^\n]", str);

    int len = strlen(str);

    int start = 0;
    for(int i = 0; i <= len; i++)
    {
        if(str[i] == ' ' || str[i] == '\0')
        {
            reves(str, start, i- 1);
            start = i + 1;

        }
    }

    printf("%s\n", str);
}