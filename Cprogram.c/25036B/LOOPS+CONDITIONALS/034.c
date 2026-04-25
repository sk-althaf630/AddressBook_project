/* Print N natural number without using loop statement.
(Hint: We use Recursion for this!)
sample input :- 5
sample output :- 1 2 3 4 5 */

#include <stdio.h>

void printNatural(int n, int current) 
{
    if (current > n) 
    {
        return; // Base case: stop when current exceeds N
    }
    printf("%d ", current);
    printNatural(n, current + 1); // Recursive call
}

int main() 
{
    int n;
    printf("Enter N: ");
    scanf("%d", &n);

    printf("Natural numbers up to %d: ", n);
    printNatural(n, 1);
    printf("\n");
    
    return 0;
}