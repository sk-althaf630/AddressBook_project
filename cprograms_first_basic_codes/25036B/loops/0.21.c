// print the left angle triangle with character
/*date :- 8 - 11- 2025*/

#include <stdio.h>
int main()
{
    int line;
    printf("enter the lines: ");
    scanf("%d", &line);

    for(int i = 0; i < line; i++)
    {
        for(int j = line - 1; j >= i; j--)
        {
            printf(" ");
        }
        for(int k = 0; k <= i; k++)
        {
            printf("%c", k + 65);
        }
        printf("\n");
    }
    return 0;
}