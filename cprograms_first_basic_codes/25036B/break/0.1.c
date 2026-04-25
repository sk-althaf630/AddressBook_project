#include <stdio.h>
int main()
{
    int i;
    for(i = 0; i < 10; i++)
    {
        printf("%d ", i);
        if(i == 5)
        {
            break;
        }
    }
    printf("\n");
    printf("out of for loop\n");

    int j = 0;
    while(j < 0)
    {
        if(j == 5)
        {
            printf("j is %d\n", j++);
            break;
        }
    }
    printf("out of while loop\n");
    
}