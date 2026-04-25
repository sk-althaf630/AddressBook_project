



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
        printf("%d ", n);
        natural(n - 1);
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