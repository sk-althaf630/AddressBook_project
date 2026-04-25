/* print change the vlues by pointers with functions
   sample:- a = 10 , change a = 20
   sample output:-before a = 10
                   after a = 20*/

#include <stdio.h>
void  fun(int *ptr);

int main()
{
    int num = 100;

    fun(&num);
    printf("%d\n", num);
}
void  fun(int *ptr)
{
    *ptr = 200;
}