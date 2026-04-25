/*Reverse the binary of a given number using a new number.
Original number: 6
Reversed binary number: 1610612736

00000000 00000000 00000000 00000110   (original)
01100000 00000000 00000000 00000000   (reversed)

The reversed binary 01100000 00000000 00000000 00000000 equals 1610612736 in decimal.
*/

#include <stdio.h>

int reverseBits(int num) {
    int rev = 0;                  // new number to store reversed bits
    int bitCount = sizeof(num) * 8; // typically 32 bits for int

    for (int i = 0; i < bitCount; i++) {
        rev = rev << 1;          // shift rev left to make space
        rev = rev | (num & 1);   // copy the LSB of num into rev
        num = num >> 1;          // shift num right to process next bit
    }
    return rev;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int reversed = reverseBits(num);

    printf("Original number: %d\n", num);
    printf("Reversed binary number: %d\n", reversed);

    return 0;
}