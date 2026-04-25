/* WAP to swap two integers.
sample input :- 10 20
sample output :- After swapping: First = 20, Second = 10 */

#include <stdio.h>

int main() 
{
    int first, second, temp;
    
    printf("Enter first and second integer: ");
    scanf("%d %d", &first, &second);

    // Using a temporary variable to hold the value
    temp = first;
    first = second;
    second = temp;

    printf("After swapping: First = %d, Second = %d\n", first, second);
    return 0;
}