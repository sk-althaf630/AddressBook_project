#include <stdio.h>

/*typedef int array_of_five_hunded[500];

int main()
{
    array_of_five_hunded arr;
    printf("%lu\n", sizeof(arr));
    return 0;
}*/

/*typedef int (*fp)(int,int);
int add(int a, int b)
{
    return a+b;
}

int main()
{
    fp  fptr;
    fptr = add;
    printf("%d\n", fptr(10, 20));
}*/

typedef struct Sensor 
{
 int id;
 char name[12];
 int version;
 /*
* The members of an anonymous union
 * are considered to be members of the
 * containing structure.
 */
 union 
 { // Anonymous union
 float temperature;
 float humidity;
 char motion[4];
 };
} Sensor;

int main()
{
    Sensor var
}