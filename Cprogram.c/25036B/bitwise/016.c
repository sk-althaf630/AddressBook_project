/*
Set/get/toggle/clear n bits at given position.

🖥️ Example Run (num = 42 → 101010)
- Set 3 bits at pos=1
Mask = 0001110 → result = 101110 = 46
- Clear 3 bits at pos=1
Mask = 0001110 → result = 100000 = 32
- Toggle 3 bits at pos=1
Mask = 0001110 → result = 100100 = 36
- Get 3 bits at pos=1
Extracted = 101 = 5
*/

#include <stdio.h>

// Set n bits at position pos
int setBits(int num, int pos, int n) {
    int mask = ((1 << n) - 1) << pos;
    return num | mask;
}

// Clear n bits at position pos
int clearBits(int num, int pos, int n) {
    int mask = ((1 << n) - 1) << pos;
    return num & ~mask;
}

// Toggle n bits at position pos
int toggleBits(int num, int pos, int n) {
    int mask = ((1 << n) - 1) << pos;
    return num ^ mask;
}

// Get n bits at position pos
int getBits(int num, int pos, int n) {
    int mask = ((1 << n) - 1) << pos;
    return (num & mask) >> pos;
}

int main() {
    int num = 42; // 101010 in binary
    int pos = 1;  // starting from bit 1
    int n = 3;    // 3 bits

    printf("Original number: %d (binary 101010)\n", num);

    printf("Set bits:   %d\n", setBits(num, pos, n));
    printf("Clear bits: %d\n", clearBits(num, pos, n));
    printf("Toggle bits:%d\n", toggleBits(num, pos, n));
    printf("Get bits:   %d\n", getBits(num, pos, n));

    return 0;
}