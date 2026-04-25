/*WAP to find the add numbers by recursive functions
    sample input:- 4
    sample output:-10*/


#include <stdio.h>
int sum_of_no(int s)
{
    if(s < 1)
    {
        return 0;
    }
    return s + sum_of_no(s - 1);
}
int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);

    printf("RES: ----> %d", sum_of_no(num));
    printf("\n");
}