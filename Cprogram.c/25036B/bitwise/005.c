/* Program to swap two integers using bitwise XOR 
Suppose a = 5 (0101), b = 3 (0011)

Step 1: a = a ^ b → 0101 ^ 0011 = 0110 (6)
Step 2: b = a ^ b → 0110 ^ 0011 = 0101 (5)
Step 3: a = a ^ b → 0110 ^ 0101 = 0011 (3)

Result: a = 3, b = 5*/

#include <stdio.h>

int main()
{
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    printf("Before swapping: a = %d, b = %d\n", a, b);

    // XOR swap logic
    a = a ^ b;  // Step 1
    b = a ^ b;  // Step 2
    a = a ^ b;  // Step 3

    printf("After swapping: a = %d, b = %d\n", a, b);

    return 0;
}


