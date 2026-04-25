#include<stdio.h>

int main()
{
    int day,month,year;
    int hour,minute,second;
    printf("Enetr the year in format day/month/year:");
    if(scanf("%d/%d/%d", day,month,year) !=3)
    {
        printf("Invalid input\n");
    }
    else
    {
        printf("date is %d/%d/%d/n", day,month,year);
    }

    printf("enter the time in format hour:minute:second : ");
    if(scanf("%d:%d:%d", &hour, &minute, &second) !=3)
    {
        printf("Invalid input\n");
    }
    else
    {
        printf("time is %d:%d:%d\n", hour, minute, second);
    }
}