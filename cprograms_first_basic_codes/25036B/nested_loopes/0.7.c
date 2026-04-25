#include <stdio.h>
int main()
{
    int i, j, line;
    printf("Enter the number of lines:");
    scanf("%d", &line);

    for(i=0;i<line;i++)  
    {
        int temp=1;
        for(j=0;j<line;j++)
        {
            if(j>=line-1-i)
            {
                printf("%d ",temp++);
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