# include <stdio.h>

int main()
{
    int marks;
    printf("Enter the number: ");
    scanf("%d", &marks);
    
    if (marks > 95 && marks <=100)
    {
        printf("grade A\n");
    }
    else if (marks >= 75 && marks <= 94)
    {
        printf("grade B\n");
    }
    else if (marks >= 65 && marks <=74)
    {
        printf("grade C\n");
    }
    else
    {
        printf("Fali D\n");
    }
    return 0;

}