// WAP to print all the longest word of string (by length).

// Enter a string: I enjoy programming in JavaScript and Python

// Longest words are:
// programming
#include <stdio.h>
#include <string.h>

int main() 
{
    char str[200];
    printf("Enter a string: ");
    scanf("%[^\n]", str);  // reads input until newline

    int maxLen = 0;
    char word[50];

    // First pass: find maximum word length
    for (int i = 0; i < strlen(str); i++) {
        int len = 0;
        while (str[i] != ' ' && str[i] != '\0') 
        {
            word[len++] = str[i++];
        }
        word[len] = '\0';
        if (len > maxLen) {
            maxLen = len;
        }
    }

    // Second pass: print words with max length
    printf("\nLongest words are:\n");
    for (int i = 0; i < strlen(str); i++) {
        int len = 0;
        while (str[i] != ' ' && str[i] != '\0') {
            word[len++] = str[i++];
        }
        word[len] = '\0';
        if (len == maxLen) {
            printf("%s\n", word);
        }
    }

    return 0;
}