#include <stdio.h>
#include <stdio_ext.h>

int main()
{
    char ch = 'y';
    while(ch != 'n')
    {
        scanf("%c", &ch);
        printf("%c", ch);
    }
}