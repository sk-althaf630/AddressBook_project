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
    int size;
    printf("Enter the size: ");
    scanf("%d", &size);
    if(size > 2)
    {
        printf("Invalid.");
        return 1;
    }
    struct student s1[size];

    for(int i = 0; i < size; i++)
    {
        printf("Enter the id: ");
         scanf("%d", &s1[i].id);

         printf("Enter the name: ");
         scanf(" %[^\n]", s1[i].name);

          printf("Enter the DOB: ");
         scanf("%d %s %d",&s1[i].DOB.Date, s1[i].DOB.month, &s1[i].DOB.year);
    }
   // printf("\n\n")
for(int i = 0; i < size;)
    printf("%d\t%s\t%d\t%s\t%d\n", s1.id, s1.name, s1.DOB.Date, s1.DOB.month, s1.DOB.year);
}