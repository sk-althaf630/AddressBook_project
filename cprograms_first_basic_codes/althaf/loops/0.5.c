/*WAP to print the powre of N number of series use the loops
    sample input:- limit --10, base --2
    sample output:- 1, 2, 4, 8, 16, 32, 64, 128, 256, 512*/

#include <stdio.h>
int main()
{
    int limit, base;
    printf("Enter the limit for loop: ");
    scanf("%d", &limit);

    printf("Enter the base value to multiplay: ");
    scanf("%d", &base);

    int ret = 1;
    printf("RES: ---> ");
    for(int i = 1; i <= limit; i++)
    {
        printf("%d ", ret);
        ret = ret * base;
    }
    printf("\n");
    return 0;
}