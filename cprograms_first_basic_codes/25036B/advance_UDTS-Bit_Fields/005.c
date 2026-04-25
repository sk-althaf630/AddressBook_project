//wap to swap the nibbles of a byte
#include<stdio.h>
typedef union nibble
{
    struct
    {
        unsigned char lower: 4;
        unsigned char upper: 4;
    }swap;
    unsigned char third;

}var;
int  main()
{
    var var1;
    printf("Enter character in hexadecimal:");
    scanf("%hhx",&var1.third);

    unsigned char temp=var1.swap.lower;
    var1.swap.lower=var1.swap.upper;
    var1.swap.upper=temp;

    printf("%hhx\n",var1.third);
}