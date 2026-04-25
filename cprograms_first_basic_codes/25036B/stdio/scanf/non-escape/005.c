#include <stdio.h>
int main()
{
    char str[] = {"my highest sore is 236"};
    int num;
    sscanf(str,"%*s %*s %*s %*s %d", &num);
    printf("---> %d\n", num);
}