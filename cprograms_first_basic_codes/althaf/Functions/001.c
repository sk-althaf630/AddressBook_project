/*WAP to return the square and cube of a number using a single function 
    sample input:- 2
    sample output:-4 and 8 */

#include <stdio.h>
void square_cube(int num, int *sq, int *cu)
{
    *sq = num * num;
    *cu = num * num * num;
}
int main()
{
    int num, sq, cu;
    printf("Enter the number: ");
    scanf("%d", &num);

    square_cube(num, &sq, &cu);
    printf("RES: %d ---> %d\n", num, sq);
    printf("RES: %d ----> %d\n", num, cu);
}