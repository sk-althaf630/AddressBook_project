// WAP to print frequency of each character of string.
// sample input:- hello
// sample output:- h-> 1 time, e -> 1 time, l -> 2 time, 0 -> 1 time

#include <stdio.h>

int main()
{
    char str[100];
    printf("Enter the string : ");
    scanf("%[^\n]", str);

    for(int i = 0; str[i] != '\0'; i++)
    {
        int flage = 0;

        for(int j = 0; j < i; j++)
        {
            if(str[i] == str[j])
            {
                flage = 1;
                break;
            }
        }

        if(flage == 1)
        {
            continue;
        }

        int count = 1;
        for(int k = i+1;  str[k] != '\0'; k++)
        {
            if(str[k] == str[i])
            {
                count++;
            }
        }
        printf("%c --> %d times\n", str[i], count);

    }

    return 0;
}