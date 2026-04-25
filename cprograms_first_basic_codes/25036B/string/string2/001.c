#include <stdio.h>
int main()
{
    char str[10];
    puts("Enter the string: ");
    fgets(str,10,stdin);
    puts(str);
    /*for(int i = 0; i < 10; i++)
    {
        printf("%d  %d\n",i,str[i]);
    }*/
}