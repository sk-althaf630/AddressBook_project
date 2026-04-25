#include <stdio.h>
#define METHOD 2
int main()
{
    #if METHOD ==1
    printf("001 ------> hello\n");
    #else
    printf("002 ------> hello\n");
    #endif
}