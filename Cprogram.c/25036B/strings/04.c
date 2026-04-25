// WAP to print each word of string (both sides).

// Enter a string: Hello World
// Forward: Hello
// Backward: olleH

// Forward: World
// Backward: dlroW

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]", str);   // simple input (unsafe, but easy for beginners)

    char *word = strtok(str, " ");  // split by space

    while (word != NULL) {
        printf("Forward: %s\n", word);

        printf("Backward: ");
        for (int i = strlen(word) - 1; i >= 0; i--) {
            printf("%c", word[i]);
        }
        printf("\n\n");

        word = strtok(NULL, " ");  // next word
    }

    return 0;
}