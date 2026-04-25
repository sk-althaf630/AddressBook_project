#include <stdio.h>
int main()
{
    char str[100];
    printf("enter the string: ");
    //scanf("%s", str);
    scanf("%[^\n]", str);  //selective scanf

    printf("you is the: %s\n", str);

    return 0;
}