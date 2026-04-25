/*
Apply circular left/right shift count times.

Enter an integer: 139
Enter shift count: 4
Original number : 139 (0x8B)
Left shift (4)  : 2224 (0x8B0)
Right shift (4) : 2684354707 (0x9FFFFFFB)

10001011 → 00101110 (wrap "10" around)
    
10001011 → 11100010 (wrap "11" around)
*/

#include <stdio.h>

// Function for circular left shift
unsigned int circularLeftShift(unsigned int num, int count) {
    int bits = sizeof(num) * 8;  // total bits in int (usually 32)
    count = count % bits;        // normalize count
    if (count == 0) return num; 
    return (num << count) | (num >> (bits - count));
}

// Function for circular right shift
unsigned int circularRightShift(unsigned int num, int count) {
    int bits = sizeof(num) * 8;
    count = count % bits;
    if (count == 0) return num; 
    return (num >> count) | (num << (bits - count));
}

int main() {
    unsigned int num;
    int count;

    printf("Enter an integer: ");
    scanf("%u", &num);

    printf("Enter shift count: ");
    scanf("%d", &count);

    printf("Original number : %u (0x%X)\n", num, num);
    printf("Left shift (%d) : %u (0x%X)\n", count, circularLeftShift(num, count), circularLeftShift(num, count));
    printf("Right shift (%d): %u (0x%X)\n", count, circularRightShift(num, count), circularRightShift(num, count));

    return 0;
}