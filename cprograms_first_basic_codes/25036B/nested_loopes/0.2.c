#include <stdio.h>
int main()
{
    int i, j, lines;
    printf("Enter the lines: ");
    scanf("%d", &lines);
    
    for(i=0;i<lines;i++)
    {
        char ch='A';
        for(j=0;j<5;j++)
        {
            printf("%c",ch++);
        }
        printf("\n");
    }
}