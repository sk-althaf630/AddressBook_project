//Bit-fields:- we  have the freedom to allocate memory in terms of bits
//not--> this is only worke for int and char, if you is double and float it gives worening
#include <stdio.h>
typedef struct nibble
{
    unsigned char lower : 4;//limit is only 8bits
    //unsigned int lower : 4;//limit is only 32bits
    unsigned char upper : 4;
}new_type;

/*int main()
{
    new_type var;
    printf("The size of the data type is %lu\nvariable is %lu\n", sizeof(new_type), sizeof(var));
}*/

int main()
{
    new_type var;
    printf("The size of the data type is %lu\nvariable is %lu\n", sizeof(new_type), sizeof(var));
}