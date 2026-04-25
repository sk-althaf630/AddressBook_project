/* WAP to print ap and gp series.
sample input :- 2 3 2 5
(first term=2, diff=3, ratio=2, terms=5)
sample output :- 
AP Series: 2 5 8 11 14 
GP Series: 2 4 8 16 32 */

#include <stdio.h>

int main() 
{
    int a, d, r, n;
    
    printf("Enter first term (a), common diff (d), common ratio (r), and N terms: ");
    scanf("%d %d %d %d", &a, &d, &r, &n);

    // AP Series
    int apTerm = a;
    printf("AP Series: ");
    for(int i = 1; i <= n; i++)
    {
        printf("%d ", apTerm);
        apTerm += d;
    }
    
    printf("\n");

    // GP Series
    int gpTerm = a;
    printf("GP Series: ");
    for(int i = 1; i <= n; i++)
    {
        printf("%d ", gpTerm);
        gpTerm *= r;
    }
    printf("\n");

    return 0;
}