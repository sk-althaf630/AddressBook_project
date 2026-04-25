#include <stdio.h>

struct student
{
    int Roll_no;
    char name[20];
    float maths;
    float English;
    float sciance;
};
void input(struct student *p)
{
    printf("Enter the Rollno: ");
    scanf("%d", &p->Roll_no);

    printf("Enter the name: ");
    scanf(" %[^\n]", p->name);

    printf("Enter the markes---M: ");
    scanf("%g", &p->maths);
    printf("Enter the markes---E: ");
    scanf("%g", &p->English);
    printf("Enter the markes---S: ");
    scanf("%g", &p->sciance);

}
float average(struct student s)
{
    return (s.maths+s.English+s.sciance)/3;
}
void display(float s)
{
    if(s >= 90.0 &&  s <= 100.0)
    {
        printf("A ---> Gread\n");
    }
    else if(s >= 75.0 &&  s <= 89.0)
    {
        printf("B ---> Gread\n");

    }
    else if(s >= 35.0 && s <= 74.0)
    {
        printf(" C---> Gread\n");
    }
    else
    {
        printf("fail\n");
    }
}

int main()
{
    struct student s1;

    input(&s1);
    float avg = average(s1);
    display(avg);
    printf("AVERAGE ---> %g\n", avg);
}