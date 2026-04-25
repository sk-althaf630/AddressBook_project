#include <stdio.h>
int main()
{
 int n = 100;
 printf("n is %d\n", n);
 
 int *ptr;
 ptr = &n;

 *ptr = 200;
 printf("n is %d\n", n);

}