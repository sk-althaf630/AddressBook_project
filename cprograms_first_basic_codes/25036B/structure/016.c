#include <stdio.h>
//#pragma pack(1)  // used to avaiod padding
struct S
{
    int n1;
    char str1[13];
    int n2;
    double dnum;
    char str2[11];
    short sh;
};

int main()
{
    printf("size is ---> %lu\n", sizeof(struct S)); //48
    struct S s;

    printf("&n1 --> %hu\n", &s.n1);//100
    printf("str1 --> %hu\n", s.str1);//1004
    printf("&n2 --> %hu\n", &s.n2);//1020
    printf("&dnum --> %hu\n", &s.dnum);//1024
    printf("str2 --> %hu\n", s.str2);//1032
    printf("&sh --> %hu\n", &s.sh);//1044

}