/*
WAP to print the decimal value of each byte of a given integer from the LSB

Enter an integer: 305419896

Decimal value of each byte (LSB first):
Byte 0: 120
Byte 1: 86
Byte 2: 52
Byte 3: 18
*/
#include <stdio.h>

int main() {
    unsigned int num;
    printf("Enter an integer: ");
    scanf("%u", &num);

    // Number of bytes in an unsigned int
    int bytes = sizeof(num);

    printf("Decimal value of each byte (LSB first):\n");
    for (int i = 0; i < bytes; i++) {
        unsigned char byte = (num >> (i * 8)) & 0xFF; // Extract each byte
        printf("Byte %d: %u\n", i, byte);
    }

    return 0;
}
