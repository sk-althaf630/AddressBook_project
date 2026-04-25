// WAP to check if the string is pangram or not.

// Enter a string: The quick brown fox jumps over the lazy dog
// Pangram

// Enter a string: Hello World
// Not a pangram
#include <stdio.h>
#include <ctype.h>

int main() {
    char str[200];
    int letters[26] = {0};   // mark each alphabet letter
    int i;

    printf("Enter a string: ");
    scanf("%[^\n]", str);   // reads until newline (safe alternative to gets)

    // mark letters found
    for (i = 0; str[i] != '\0'; i++) 
    {
        if (isalpha(str[i])) 
        {
            char ch = tolower(str[i]);
            letters[ch - 'a'] = 1;
        }
    }

    // check if all letters are present
    for (i = 0; i < 26; i++) 
    {
        if (letters[i] == 0) 
        {
            printf("Not a pangram\n");
            return 0;
        }
    }

    printf("Pangram\n");
    return 0;
}