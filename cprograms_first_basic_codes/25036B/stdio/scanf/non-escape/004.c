#include <stdio.h>
int main()
{
    char str[] = {"4 + 23.8 is 657.445656"};
    int a;
    char ch;
    float f;
    char str1[10];
    double d;
    sscanf(str,"%d %c %f %s %lf", &a, &ch, &f, str1, &d);
    printf("%d %c %f %s %lf\n",a, ch, f, str1, d);
}