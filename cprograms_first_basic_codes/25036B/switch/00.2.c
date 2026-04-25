#include <stdio.h>
int main()
{
    char ch;
    printf("Enter the character: ");
    scanf("%c", &ch);
    switch(ch)
    {
        case 'a':
        case 'A':
        printf("the character is a\n");
        break;
        case 'b':
        case 'B':
        printf("the character is b\n");
        break;
        case 'c':
        case 'C':
        printf("the character is c\n");
        break;
        case 'd':
        case 'D':
        printf("the character is d\n");
        break;
        case 'f':
        case 'F':
        printf("the character is f\n");
        break;
        default:
        printf("num is default\n");

  
    }
    return 0;
}