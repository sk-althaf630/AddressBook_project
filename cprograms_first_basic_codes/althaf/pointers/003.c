/* WAP to sum and product the numbers by the pointer functions
   sample:- n1 = 3, n2 = 6
   sample output:-sum = n1 + n2 ---> 9
                   product = n1 * n2 ---> 18*/

#include <stdio.h>
void sum_pro(int n1, int n2, int *sum, int *pro);

int main()
{
    int num1;
    printf("Enter the num1: ");
    scanf("%d", &num1);

    int num2;
    printf("Enter the num2: ");
    scanf("%d", &num2);

    int sum, pro;
    sum_pro(num1,num2,&sum,&pro);
    printf("sum --> %d\npro --> %d\n", sum, pro);
}

void sum_pro(int n1, int n2, int *sum, int *pro)
{
    *sum = n1 + n2;
    *pro = n1 * n2;
}