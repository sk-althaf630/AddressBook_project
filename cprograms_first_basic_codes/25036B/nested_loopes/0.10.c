#include <stdio.h>
int main()
{
    int i, j, line;
    printf("Enter the number of lines:");
    scanf("%d", &line);

    for(i=0;i<line;i++)  
    {
        for(j=0;j< line;j++)
        {
            if(i == 0 || i  == line - 1 )
            {
                printf("-");
            }
            else if(j==0 || j == line - 1)
            {
                printf("|");
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