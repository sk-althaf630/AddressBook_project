/* Print the table of a given number up to the limit ‘L’.
sample input :- 3 5 (number=3, limit=5)
sample output :- 
3 x 1 = 3
3 x 2 = 6
3 x 3 = 9
3 x 4 = 12
3 x 5 = 15 */

#include <stdio.h>

int main() 
{
    int num, limit;
    
    printf("Enter the number and the limit L: ");
    scanf("%d %d", &num, &limit);

    for(int i = 1; i <= limit; i++)
    {
        printf("%d x %d = %d\n", num, i, num * i);
    }

    return 0;
}