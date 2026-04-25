#include <stdio.h>
int main()
{
    int n = 1;

    label:
    printf("%d", n++);
    if(n < 11)
    {
        goto label;
        printf("\n");
    
    }
}