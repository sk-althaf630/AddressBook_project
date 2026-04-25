#include <stdio.h>
struct student
{
    int id;
    char name[20];
    char add[60];
    float marks;
}s2, s3, s4; //g;pba; variables
int main()
{
    struct student s1 = {.name = "emertex", .id = 101, .marks = 98.5, .add = "karnataka", };
    printf("id is ---> %hhu\n", &s1.id);
    printf("name is ---> %hhu\n", s1.name);
    printf("add is ---> %hhu\n", s1.add);
    printf("marks is ---> %hhu\n", &s1.marks);

}