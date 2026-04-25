//WAP to print only repeated characters of the string.
// sample input :- hello
// sample output :- l

#include <stdio.h>

int main()
{
    char str[100];
    printf("Enter the string : ");
    scanf("%[^\n]", str);

    printf("repeated characters in the string : ");
    for(int i = 0; str[i] ; i++)
    {
        int repeated = 0;
        for(int j = 0; j < i ; j++)
        {
            if(str[i] == str[j])
            {
                repeated  = 1;
            }
        }

        if(repeated == 1)
        {
            printf("%c", str[i]);
        }
    }
    printf("\n");

    return 0;
}