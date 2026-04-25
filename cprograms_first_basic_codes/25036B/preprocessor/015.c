#include <stdio.h>
#include <stdlib.h>
#if defined (STATIC) || defined(DYNAMIC)
#define SIZE 10
#else
#error "memory has not allocated by useing -D DYNAMIC  while commed line"
#endif

int main()
{
    #if defined STATIC
    char str[SIZE];
    #elif defined DYNAMIC
    char *str = malloc (10 *sizeof(char));
    #endif
    
    #if defined (STATIC)  || defined(DYNAMIC)
    scanf("%s", str);
    printf("%s\n", str);
    #endif

}