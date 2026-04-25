#include <stdio.h>

int main()
{
    int score;
    char grade;

    printf("Enter the score: ");
    scanf("%d", &score);

    printf("Enter the grade: ");
    scanf("%c", &grade);

    if (score >= 90)
    {
        grade ='A';
        printf("very good\n");
    }
    else if (score >= 60)
    {
        grade = 'B';
        printf("good job\n");
    }
    else if (score >= 40)
    {
        grade = 'C';
        printf("pass\n");
    }
    else
    {
        grade = 'D';
        printf("Fail\n");
    }

    printf("THis your Grade: %c\n", grade);

    return 0;
}