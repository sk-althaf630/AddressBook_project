/* WAP to print positive fibonacci series.
sample input :- 7
sample output :- 0 1 1 2 3 5 8 */

#include <stdio.h>

int main() 
{
    int n, t1 = 0, t2 = 1, nextTerm;
    
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");
    for (int i = 1; i <= n; ++i) 
    {
        printf("%d ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");

    return 0;
}