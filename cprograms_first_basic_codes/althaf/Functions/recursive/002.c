/*WAP to find the multiplucation by recursive functions
    sample input:- 4
    sample output:-24*/

#include <stdio.h>
int fun(int m)
{
    if(m <= 1)
    {
        return 1;
    }
    else
    {
        return m * fun(m -1);
    }
}
int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);

    int ret = fun(num);
    printf("RES: ----> %d\n", ret);
}