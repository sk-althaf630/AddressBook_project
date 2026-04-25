# include <stdio.h>
 
int main()
{ 
    char ch;
    int num;
    float fnum;
    double dnum;

    printf("Enter a character: ");
    scanf("%c",&ch);

    printf("Enter the number: ");
    scanf("%d",&num);

    printf("Enter float value: ");
    scanf("%f",&fnum);

    printf("Enter double value: ");
    scanf("%lf",&dnum);

    printf("%c %d %f %lf\n", ch, num, fnum, dnum);

    return 0;
}