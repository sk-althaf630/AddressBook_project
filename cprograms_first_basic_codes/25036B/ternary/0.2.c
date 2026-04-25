#include <stdio.h>
int main()
{
    int n;
    printf("numbers:");
    scanf("%d", &n);

   // n % 2  ? (n > 0 ? printf(" positive odd\n") : printf("negative odd\n") ) : printf("even\n");
   n > 0 ? (n % 2 ? printf("positive and odd\n") : printf("positive and even\n")) : 
   (n == 0 ? printf("zero\n"):
   (n % 2 ? printf("negative and odd\n") : printf("negative and even\n"));
     

    return 0;
}