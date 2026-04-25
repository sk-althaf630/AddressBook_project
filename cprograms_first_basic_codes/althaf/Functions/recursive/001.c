/*WAP to print natural numbers by revarsal by recursive functions
    sample input:- 5
    sample output:-5 4 3 2 1*/

#include <stdio.h>
void natural_number_reverse(int r)
{
    //base condition
    if(r < 1)
    {
        return;
    }
    printf("%d ", r);
    natural_number_reverse(r-1);
}
int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);

    natural_number_reverse(num);
    printf("\n");
}