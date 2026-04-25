#include<stdio.h>
int main()
{
    char ch;
    int a;
    int ret = scanf("%c%d",&ch,&a);
    printf("%c ----%d\n",ch, a);
    printf("%d\n",ret);
}