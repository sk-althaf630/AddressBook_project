//WAP to remove all characters of the second string into the first string.
// sample input :- strin 1 --> programming
//                 string 2---> gm
// sample output :- prorain
#include <stdio.h>
#include <string.h>

int main() {
    char str1[200], str2[100], result[200];
    printf("Enter the first string: ");
    scanf(" %[^\n]", str1);

    printf("Enter the second string: ");
    scanf(" %[^\n]", str2);

    int i = 0, j = 0;
    while (str1[i] != '\0') {
        int remove = 0;  // flag to check if character should be removed

        // Check if str1[i] exists in str2
        for (int k = 0; str2[k] != '\0'; k++) {
            if (str1[i] == str2[k]) {
                remove = 1;
                break;
            }
        }

        // If not found in str2, copy to result
        if (!remove) {
            result[j++] = str1[i];
        }

        i++;
    }

    result[j] = '\0';  // terminate result string

    printf("String after removal: %s\n", result);
    return 0;
}