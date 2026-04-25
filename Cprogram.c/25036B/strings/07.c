// WAP to take the string like “Q2ero4wertg1K” to give output like “erwertK”.

// Enter a string: Q2ero4wertg1K
// Output: erwert

#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100], result[100];
    int j = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (islower(str[i])) 
        {   // keep only lowercase letters
            result[j++] = str[i];
        }
    }
    result[j] = '\0';

    printf("Output: %s\n", result);

    return 0;
}