/*
Find the XOR value of two numbers without ^ operator.


Enter two integers: 5 3
XOR of 5 and 3 = 6

a = 5 → 0101
b = 3 → 0011
----------------
(a & ~b) = 0100
(~a & b) = 0010
OR result = 0110 → 6
*/

#include <stdio.h>

int main() {
    int a, b, xor_val;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    // XOR using only AND, OR, NOT
    xor_val = (a & ~b) | (~a & b);

    printf("XOR of %d and %d = %d\n", a, b, xor_val);

    return 0;
}