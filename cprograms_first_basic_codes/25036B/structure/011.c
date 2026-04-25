#include <stdio.h>
struct player 
{
    int number;
    char name[30];
    char team[30];
};

void display(struct player *p,int size)
{
    for(int i = 0; i <size; i++)
    {
        printf("%d %s  %s\n", p[i].number,p[i].name,p[i].team);
    }
}
int main()
{
    struct player p[3];
    for(int i = 0; i < 3; i++)
    {
        printf("Enter the number for [%d]: ", i + 1);
        scanf("%d", &p[i].number);
        printf("Enter the name for [%d]: ", i + 1);
        scanf(" %[^\n]", p[i].name);
        printf("Enter the tame for [%d]: ", i + 1);
        scanf(" %[^\n]", p[i].team);
    }
    display(p,3);
}