/* WAP to find LCM of two numbers.
sample input :- 12 15
sample output :- LCM of 12 and 15 is 60. */

#include <stdio.h>

int main() 
{
    int n1, n2, max;
    
    printf("Enter two positive integers: ");
    scanf("%d %d", &n1, &n2);

    // Maximum number between n1 and n2 is stored in max
    max = (n1 > n2) ? n1 : n2;

    while (1) 
    {
        if (max % n1 == 0 && max % n2 == 0) 
        {
            printf("LCM of %d and %d is %d.\n", n1, n2, max);
            break;
        }
        ++max;
    }
    return 0;
}