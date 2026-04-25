#include <stdio.h>
#define METHOD 5
int main()
{
    #if METHOD ==1
    printf("001 ------> hello\n");
    #elif METHOD == 5
    printf("004 -----> main\n");
    #else
    printf("002 ------> hello\n");
    #endif
}