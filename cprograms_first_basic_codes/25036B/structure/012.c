#include <stdio.h>
struct student
{
    int Roll_number;
    char name[20];
    float maths;
    float English;
    float science;
    float avg;
};

void input(struct student *s, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("Enter the Roll number of student[%d]: ", i+1);
        scanf("%d", &s[i].Roll_number);
        printf("Enter the name of student[%d]: ", i+1);
        scanf(" %[^\n]", s[i].name);
        printf("Enter the markes in MATHS[%d]: ", i+1);
        scanf("%f", &s[i].maths);
        printf("Enter the markes in ENGLISH[%d]: ", i+1);
        scanf("%f", &s[i].English);
        printf("Enter the markes in SCIENCE[%d]: ", i+1);
        scanf("%f", &s[i].science);
    }
}

void average(struct student *a, int size)
{
    for(int i = 0; i < size; i++)
    {
        a[i].avg = (a[i].maths + a[i].English + a[i].science)/3;
    }
}
void sort(struct student *a, int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - 1 - i; j++)
        {
            struct student s;
            if(a[j].Roll_number > a[j + 1].Roll_number)
            {
                s = a[j + 1];
                a[j + 1] = a[j];
                a[j] = s;
            }
        }
    }
}
void display(struct student *a, int size)
{
    printf("ROLL\tNAME\t\tAVERAGE\n");
    for(int i = 0; i < size; i++)
    {
       printf("%d\t%s\t\t%f\n", a[i].Roll_number, a[i].name, a[i].avg);
    }
}

int main()
{
    int size;
    printf("Enter the size: ");
    scanf("%d", &size);
    if(size <= 1)
    {
        printf("Invalid  size it should be >2.");
        return 1;
    }
    struct student s[size];
    input(s,size);


    average(s,size);

    sort(s,size);

    display(s,size);

    return 0;
}