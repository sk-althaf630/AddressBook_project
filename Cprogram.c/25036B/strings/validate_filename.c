//WAP to validate a file name is with extension ‘.c’ or not.
// sample input :- file.c
// sample output :- Valid: The file has a .c extension.

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    printf("Enter the filename with extention : ");
    scanf("%[^\n]", str);

    int len = strlen(str);

    if(len > 2 && str[len - 2] == '.' && str[len - 1] == 'c')
    {
        printf("Valid: The file has a .c extension.\n");
    }
    else
    {
        printf("Invalid: The file does not have a .c extension.\n");
    }

    return 0;
}