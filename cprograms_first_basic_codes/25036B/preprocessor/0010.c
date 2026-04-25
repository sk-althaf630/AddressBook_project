#include <stdio.h>
#define MACRO 100  //IF NOT DEFINES HERE DEFINE IT IN ARGUMENT LIDE GCC -D 0010.c MACRO=100
int main()
{
    #ifdef MACRO
    printf("hello world\n");
    printf("%d\n", MACRO);
    #endif
}