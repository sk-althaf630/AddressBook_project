#include <stdio.h>
int main()
{
    int i, j, k, lines;
    printf("Enter the lines: ");
    scanf("%d", &lines);

    for(i = 0; i < lines; i++)
    {
        char ch = 'A';
        for(j = 0; j < lines; j++)
        {
            if(j >= lines - 1 - i)
            {
                printf("%c ", ch++);
            }
            else
            {
                printf("  ");
            }
        }
        ch--;
        for(k = i; k > 0; k--)
        {
        printf("%c ", --ch);
        }
        printf("\n");
    }
}