//WAP to remove duplicates
// sample input :- hello
// sample output:- helo

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    printf("Enter the string: ");
    scanf("%[^\n]", str);

    int len = strlen(str);
    int j = 0;  // index for new string

    for (int i = 0; i < len; i++)
    {
        int duplicate = 0;
        // check if str[i] already appeared in the new string
        for (int k = 0; k < j; k++)
        {
            if (str[i] == str[k])
            {
                duplicate = 1;
                break;
            }
        }
        if (!duplicate)
        {
            str[j++] = str[i];  // keep unique character
        }
    }

    str[j] = '\0';  // terminate the new string

    printf("String after removing duplicates: %s\n", str);

    return 0;
}