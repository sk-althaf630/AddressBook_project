#include <stdio.h>
#define METHOD1
int main()
{
    #if defined (METHOD1)
    printf("Today is Friday\n");
    #endif

    #if defined (METHOD2)
    printf("hello its me\n");
    #endif

    #if defined(METHOD1) && defined(METHOD2)
    puts("hello world");
    printf("hello world\n");
    #endif

    return 0;
}