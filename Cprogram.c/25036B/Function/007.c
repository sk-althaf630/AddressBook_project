//showing given number +ve or -ve
/*sample i/p = 4
  sample o/p = +ve*/



#include <stdio.h>
int pos_neg(int num)
{
    if(num > 0)
    {
        return 1;
    }
    else if(num < 0)
    {
        return -1;
    }
    else{
        return 0;
    }
}
int main()
{
    int num;
    printf("enter the num: ");
    scanf("%d", &num);

    int res = pos_neg(num);
    if(res == 0)
    {
        printf("number is zero\n");
    }
    else if(res == 1)
    {
        printf("num is positive\n");
    }
    else
    {
        printf("num is negative\n");
    }
    return 0;
}