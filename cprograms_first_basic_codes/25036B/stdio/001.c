#include<stdio.h>
int main()
{
    char str[100];
    int x = 45, y = 18;
    char ch = '+';
    char s[] = "is";
    float f = 46.214213;
    sprintf(str,"%d %c %d %s %f",x,ch,y,s,f);
    printf("%s\n",str);
}