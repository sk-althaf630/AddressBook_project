// WAP to take a binary(0/1) string and print its decimal value.
// Enter a binary string: 1011
// Decimal value: 11
#include <stdio.h>
#include <string.h>

int main() {
    char binary[65];   // to store binary string (up to 64 bits)
    unsigned long long decimal = 0;
    int i;

    printf("Enter a binary string: ");
    scanf("%s", binary);

    // Go through each character in the string
    for (i = 0; i < strlen(binary); i++) {
        // Multiply current decimal value by 2 (shift left)
        decimal = decimal * 2;

        // Add the current bit (0 or 1)
        if (binary[i] == '1') {
            decimal = decimal + 1;
        }
    }

    printf("Decimal value: %llu\n", decimal);

    return 0;
}