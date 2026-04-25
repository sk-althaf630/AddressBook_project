//WAP to check if a string is unique or not.
// sample input:- hello
// sample output :- not unique, bucese of l repeted.


#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    printf("Enter the string : ");
    scanf("%[^\n]", str);

    int flag = 0; 
    int len = strlen(str);

    for(int i = 0; i < len; i++)
    {
        char ch = str[i];
        for(int j = 0; j < len; j++)
        {
            if(i == j)
            {
                continue;
            }
            else
            {
                if(str[i] == str[j])
                {
                    flag = 1;
                    break;
                }
            }
        }
    }

    if(flag == 1)
    {
        printf("This string is not unique\n");
    }
    else
    {
        printf("This string is unique\n");
    }

    return 0;
}