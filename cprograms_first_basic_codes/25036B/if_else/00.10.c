#include <stdio.h>

int main()
{
    int n1, n2, n3;

    printf("Enter the 3 number: ");
    scanf("%d%d%d", &n1, &n2, &n3);
    if (n1 > n2)
    {
        if (n1 > n3)
        {
            printf("n1 is larger\n");

        }
        else
        {
            printf("n3 is larger\n");
        }

    }
    else
    {
        if (n2 > n3)
        {
            printf("n2 is larger\n");
        }
        else
        {
            printf("n3 is larger\n")
        }
    }
    return 0;
}    

