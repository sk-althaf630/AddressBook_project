#include <stdio.h>
int main()
{
    int i, j, line, limit;
    printf("Enter the number of lines:");
    scanf("%d", &line);
    printf("Enter the number of limits:");
    scanf("%d", &limit);

    for(i=0;i<line;i++)  
    {
        for(j=0;j< limit;j++)
        {
            if(i == 0 || i  == line - 1 || j == 0 || j == limit - 1)
            {
                printf("*");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}