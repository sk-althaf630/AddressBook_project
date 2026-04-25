/*print 0 to limit even and odd numbers
    sample input:- 10
    sample output:-even--> 0,2,4,6,8,10
                    odd -->1,3,5,7,9*/


#include <stdio.h>
int main()
{
    int limit, sum =0;
    printf("Enter the number: ");
    scanf("%d", &limit);

    printf("even -->");
    for(int i = 0; i <= limit;i += 2)
    {
        printf("%d ", i);
    }
    printf("\n");
    printf("odd -->");
    for(int i = 1; i <= limit;i += 2)
    {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}