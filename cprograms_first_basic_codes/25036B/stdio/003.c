#include <stdio.h>
#include <ctype.h>

int main()
{
    char ch;
    for( ; (ch = getchar()) != EOF; )
    {
        putchar(toupper(ch));
    }
    puts("EOF Received");
    return 0;
}