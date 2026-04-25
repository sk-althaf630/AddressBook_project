/* print change the vlues by pointers
   sample:- a = 10 , change a = 20
   sample output:-before a = 10
                   after a = 20*/


#include <stdio.h>
int main()
{
    int  a = 10;
    printf("Before ----> %d\n", a);

    int * ptr;
    ptr = &a;
    
    *ptr = 20;
    printf("%d\n", a);
}