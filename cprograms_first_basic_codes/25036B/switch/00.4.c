#include <stdio.h>
int main()
{
    char ch;
    printf("Enter the character:\n");
    scanf("%c", &ch);

    switch(ch)
    {
        case 'n':
        case 'N':
        printf("Direction is North\n");
        break;

        case 's':
        case 'S':
        printf("Direction is South\n");
        break;

        case 'w':
        case 'W':
        printf("Direction is West\n");
        break;

        case 'e':
        case 'E':
        printf("Direction is East\n");
        break;

        default:
        printf("Invalid direction\n");
    }
    return 0;
}