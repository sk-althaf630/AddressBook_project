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
    struct student s1;
    printf("size of struct ----> %lu\n", sizeof(s1));
    printf("size of struct ----> %lu\n", sizeof(struct student));

}