/*
Swap nibble of a byte.

Enter an integer: 300
Original int : 300
Lowest byte  : 0x2C (44)
Swapped byte : 0xC2 (194)

Enter an integer: -117
Original int : -117
Lowest byte  : 0x8B (139)
Swapped byte : 0xB8 (184)

Input: [UpperNibble | LowerNibble]
Swap : [LowerNibble | UpperNibble]
*/

#include <stdio.h>

int main() {
    int num;   // signed int input
    
    printf("Enter an integer: ");
    scanf("%d", &num);
    
    // Extract only the lowest byte (8 bits)
    unsigned char byte = num & 0xFF;
    
    // Swap nibbles
    unsigned char swapped = ((byte & 0x0F) << 4) | ((byte & 0xF0) >> 4);
    
    // Show results
    printf("Original int : %d\n", num);
    printf("Lowest byte  : 0x%X (%u)\n", byte, byte);
    printf("Swapped byte : 0x%X (%u)\n", swapped, swapped);
    
    return 0;
}