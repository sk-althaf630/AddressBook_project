#include<stdio.h>//Write a program to set the nth bit of a number
int main()
{
    int n,num;
    printf("Enter num: ");
    scanf("%x",&num);
    printf("Enter n value: ");
    scanf("%d",&n);
    int mask = 1<<n;//1<<n-1
   printf("%x",num|mask);
}