/*Print n bits from LSB.

sample input:-
Enter the hexadecimal number : 10
Enter the bit position (0-based index): 4

sample output:-
Bit value at position 4 : 1
Binary (LSB -> MSB, 5 bits): 10000*/

#include <stdio.h>

// Function to print n bits from LSB of a number
void printNBitsFromLSB(int num, int n) {
    printf("Binary (LSB -> MSB, %d bits): ", n);
    for (int i = n-1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main()
{
    int num;
    printf("Enter the hexadecimal number : ");
    scanf("%x", &num);

    int n;
    printf("Enter the bit position (0-based index): ");
    scanf("%d", &n);

    // Get bit at position n
    int mask_get = (num >> n) & 1;

    printf("\n================= GET RESULT =================\n");
    printf("Bit value at position %d : %d\n", n, mask_get);

    // Print n bits from LSB
    printNBitsFromLSB(num, n+1);  // print up to the requested bit
    printf("==============================================\n");

    return 0;
}