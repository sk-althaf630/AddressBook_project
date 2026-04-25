#include <stdio.h>
struct student
{
    int id;
    char name[20];
    struct
    {
        int Date;
        char month[12];
        int year;
    }DOB;
};

int main()
{
    struct student s1;

    printf("Enter the id: ");
    scanf("%d", &s1.id);

    printf("Enter the name: ");
    scanf(" %[^\n]", s1.name);

    printf("Enter the Date: ");
    scanf("%d", &s1.DOB.Date);

    printf("Enter the month: ");
    scanf(" %[^\n]", s1.DOB.month);

    printf("Enter the year: ");
    scanf("%d", &s1.DOB.year);

    printf("%d\t%s\t%d\t%s\t%d\n", s1.id, s1.name, s1.DOB.Date, s1.DOB.month, s1.DOB.year);
}