// WAP to print all the smallest word of string (by length).
// Enter a string: cat bat elephant dog
// Smallest word(s):
// cat
// bat
// dog

#include <stdio.h>
#include <string.h>

int main() {
    char str[200];
    char word[50];
    int i, j, len, minLen = 999;
    char smallestWords[50][50]; // store multiple smallest words
    int count = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    len = strlen(str);

    // First pass: find minimum word length
    i = 0;
    while (i < len) {
        j = 0;
        while (i < len && str[i] != ' ' && str[i] != '\n') {
            word[j++] = str[i++];
        }
        word[j] = '\0';

        if (j > 0 && j < minLen) {
            minLen = j;
        }
        i++;
    }

    // Second pass: collect all words with minLen
    i = 0;
    while (i < len) {
        j = 0;
        while (i < len && str[i] != ' ' && str[i] != '\n') {
            word[j++] = str[i++];
        }
        word[j] = '\0';

        if (j == minLen) {
            strcpy(smallestWords[count++], word);
        }
        i++;
    }

    // Print results
    printf("Smallest word(s):\n");
    for (i = 0; i < count; i++) {
        printf("%s\n", smallestWords[i]);
    }

    return 0;
}