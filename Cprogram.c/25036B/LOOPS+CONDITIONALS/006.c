/* WAP to Find Largest/Smallest of three numbers.
sample input :- 10 50 25
sample output :- Largest is 50, Smallest is 10. */
#include <stdio.h>

int main() 
{
    int a, b, c, max, min;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    max = a; min = a;

    if(b > max) max = b;
    if(c > max) max = c;
    
    if(b < min) min = b;
    if(c < min) min = c;

    printf("Largest is %d, Smallest is %d.\n", max, min);
    return 0;
}