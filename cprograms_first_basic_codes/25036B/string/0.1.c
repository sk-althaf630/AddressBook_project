#include <stdio.h>

int main()
{
    char str[100] = {"hello its me , opent the gate"};

   // for{int i = 0; str[i] != \0; i++}
    //{
   //     printf("%c", str[i]);
   // }
   // printf("\n");

    printf("%s\n", str);

    str[4] = 'A';
    printf("%s\n", str);
}