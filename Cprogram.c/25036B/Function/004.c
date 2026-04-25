#include <stdio.h>
int even_odd(int n)
{
    
  return n % 2;

}
int main()
{
    int num;
    printf("enter the nums: ");
    scanf("%d", &num);
    int res = even_odd(num);

    if(res == 0)
    {
        printf("even\n");
    }
    else
    {
        printf("odd\n");
    }
}