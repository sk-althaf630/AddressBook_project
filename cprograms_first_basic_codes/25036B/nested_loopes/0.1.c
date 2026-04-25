#include <stdio.h>
int main()
{
    int i, j, lines, limit;
    printf("Enter the lines and limit: ");
    scanf("%d%d", &lines, &limit);
    
    for(i=0;i<lines;i++)
    {
        for(j=0;j<limit;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}