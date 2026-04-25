#include <stdio.h>
#include <string.h>

struct student
{
    int id;
    char name[20];
    char add[60];
    float marks;
}; //g;pba; variables

int main()
{
    struct student s1;
    int num1;
    num1 = 200;
    int num2;
    num1 = num2;

    s1.id = 201;
    printf("id is --> %d\n", s1.id);

    strcpy(s1.name,"althaf");
    strcpy(s1.add,"AP");
    s1.marks = 98.9;

    struct student s2;
    s2 = s1;

    printf("%d\n%s\n%s\n%g\n", s2.id, s2.name, s2.add, s2.marks);
}