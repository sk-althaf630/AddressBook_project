#include <stdio.h>
int main()
{
    int i, j, lines;
    printf("Enter the lines: ");
    scanf("%d", &lines);
    char ch='A';
    
    for(i=0;i<lines;i++)
    {
        for(j=0;j<=i;j++)
        {
            printf("%c ", ch++);
        }
        printf("\n");
    }
    return 0;
}