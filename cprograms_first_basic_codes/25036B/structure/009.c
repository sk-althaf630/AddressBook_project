#include <stdio.h>
struct  player
{
    int number;
    char name[20];
    char team[20];
};
void display(struct player *p1, struct player p2)
{
    p1 -> number = 200;
    p2.number = 500;
}

int main()
{
    struct player p1,p2;

   /* printf("Enter the jersy number: ");
    scanf("%d", &p1.number);
    printf("Enter the name: ");
    scanf(" %[^\n]", p1.name);
    printf("Enter the team: ");
    scanf(" %[^\n]", p1.team);
    
    struct player *ptr = &p1;

    printf("%d", ptr -> number);//(->) use in case of struct pointer*/

    p1.number = 100;
    p2.number = 150;

    printf("p1  %d\np2  %d\n", p1.number, p2.number);

    display(&p1,p2);
    printf("p1  %d\np2  %d\n", p1.number, p2.number);
    
}