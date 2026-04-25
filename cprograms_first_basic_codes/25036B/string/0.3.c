#include <stdio.h>
int main()
{
    char str1[100];
    char str2[100];

    printf("enter the first string: ");
    scanf("%[^\n]", str1);
    getchar(); //use toread 1char from stdin buffer.

    printf("enter the first string: ");
    scanf(" %[^\n]", str2);//her space it used for elemenates the space,\n,\t

    printf("res1: %s\n", str1);
    printf("res2: %s\n", str2);

}