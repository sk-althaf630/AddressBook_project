/*Get n bits from LSB and print value.
sample input:- 
Enter the hexadecimal number : 10
Enter how many bits to get from LSB: 4

sample output:-
Original number (hex)     : 10
Original number (binary)  : 0000 0000 0000 0000 0001 0000
Extracted 4 bits (value)  : 0 (hex: 0)
Extracted bits (binary)   : 0000*/

#include <stdio.h>

// Function to print n bits from LSB of a number
void printNBitsFromLSB(int num, int n) {
    printf("Binary (LSB -> MSB, %d bits): ", n);
    for (int i = n - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main() {
    int num;
    printf("Enter the hexadecimal number : ");
    scanf("%x", &num);

    int n;
    printf("Enter how many bits to get from LSB: ");
    scanf("%d", &n);

    // Mask to get n bits from LSB
    int mask = (1 << n) - 1;   // creates n ones in binary
    int value = num & mask;    // extract n bits

    printf("\n================= RESULT =================\n");
    printf("Value of %d LSB bits : %d\n", n, value);

    // Print those n bits
    printNBitsFromLSB(num, n);
    printf("==========================================\n");

    return 0;
}