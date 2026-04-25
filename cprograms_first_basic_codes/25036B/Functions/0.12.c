



#include <stdio.h>
void natural(int n)
{
    //base condition
    if(n< 1)
    {
        return;
    }
    else
    {
        natural(n - 1);
        printf("%d ", n);
    }
}

int main()
{
    int num;
    printf("enter the num: ");
    scanf("%d", &num);

    natural(num);
    printf("\n");
}