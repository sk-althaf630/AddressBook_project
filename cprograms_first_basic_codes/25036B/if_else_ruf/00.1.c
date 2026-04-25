#include <stdio.h>

int main()
{
    int Age;

    printf("Enter the number: ");
    scanf("%d", &Age);

    if (Age >= 20)
    {
        printf("yes you can apply for vote\n");
    }
    else
    {
        printf("no you can't apply for vote\n");
    }
    printf("Ending\n");
    
}