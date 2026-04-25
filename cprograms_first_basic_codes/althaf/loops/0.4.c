/*WAP to print the power of two series using loop
    sample input:- 10
    sample output:- 1, 2, 4, 8, 16, 32, 64, 128, 256, 512*/

#include <stdio.h>
int main()
{
    int limit;
    int count = 1;

    printf("Enter the limit: ");
    scanf("%d", &limit);

    printf("RES ---> ");
    for(int i = 0; i < limit; i++)
    {
        printf("%d ", count);
        count = count * 2;
    }
    printf("\n");
    return 0;
}