#include <stdio.h>//we can do this in while loope also
int main()
{
    int i, j, lines;
    printf("Enter the lines: ");
    scanf("%d", &lines);
    
    for(i=0;i<lines;i++)
    {
        for(j=0;j<=i;j++)
        {
            printf("%d ", j+1);
        }
        printf("\n");
    }
    return 0;
}