//WAP to convert multiple spaces into single spaces of the string.
// sample input :- Hello     world   from   C
// sample output :- After removing extra spaces: Hello world from C


#include <stdio.h>

int main()
{
    char str[200];
    printf("Enter the string: ");
    scanf("%[^\n]", str);   // read full line including spaces

    int i = 0, j = 0;
    int spaceFlag = 0;      // tracks if last character was a space

    while (str[i] != '\0')
    {
        if (str[i] != ' ')
        {
            // copy normal character
            str[j++] = str[i];
            spaceFlag = 0;  // reset flag
        }
        else
        {
            // only copy first space
            if (spaceFlag == 0)
            {
                str[j++] = ' ';
                spaceFlag = 1;  // mark that we saw a space
            }
            // if spaceFlag == 1, skip extra spaces
        }
        i++;
    }

    str[j] = '\0';  // terminate the new string

    printf("After removing extra spaces: %s\n", str);

    return 0;
}