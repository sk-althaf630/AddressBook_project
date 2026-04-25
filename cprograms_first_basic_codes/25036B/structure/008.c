#include <stdio.h>
struct  player
{
    int number;
    char name[20];
    char team[20];
};

int main()
{
    struct player p1;

    printf("Enter the jersy number: ");
    scanf("%d", &p1.number);
    printf("Enter the name: ");
    scanf(" %[^\n]", p1.name);
    printf("Enter the team: ");
    scanf(" %[^\n]", p1.team);
    
    struct player *ptr = &p1;

    printf("%d", ptr -> number);//(->) use in case of struct pointer

}