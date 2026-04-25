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
    struct student s1 = {101, "emertex", "karnataka", 98.5};
    printf("id is ---> %d\n", s1.id);
    printf("name is ---> %s\n", s1.name);
    printf("add is ---> %s\n", s1.add);
    printf("marks is ---> %g\n", s1.marks);

}