/* WAP to print 2 power series up to N terms.
sample input :- 5
sample output :- 2 4 8 16 32 */
#include <stdio.h>

int main() 
{
    int n, term = 2;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) 
    {
        printf("%d ", term);
        term *= 2;
    }
    printf("\n");
    return 0;
}