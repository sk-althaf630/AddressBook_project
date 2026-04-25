#include <stdio.h>
int main()
{
    int i, j, lines;
    printf("Enter the lines: ");
    scanf("%d", &lines);
    char ch='A';

    for(i=0;i<lines;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%c",ch+1);
        }
        printf("\n");
    }
}