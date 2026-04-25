// this is my first code
/*description;
     Date:- 14 th oct 2025
     Time:- 11:30h
     code Name:- 
     sample input:-
     sample output:-
                              */
#include <stdio.h>

int main()
{
    int n1, n2, n3;
    float avg;

    printf("Enter the numbers: ");
    scanf("%d%d%d", &n1, &n2, &n3);

    avg = (float) (n1+n2+n3)/3.0;

    printf("avg is %g\n", avg);

    return 0;
}