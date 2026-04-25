//WAP to implement strtok().
// Enter a string: Hello, World from C
// Token: Hello,
// Token: World
// Token: from
// Token: C

#include <stdio.h>

// Custom strtok implementation
char* myStrtok(char* str, const char* delim) 
{
    static char* input = NULL;  // static pointer to remember position
    if (str != NULL) 
    {
        input = str;  // initialize with new string
    }
    if (input == NULL) 
    {
        return NULL;  // no more tokens
    }

    // Skip leading delimiters
    char* tokenStart = input;
    while (*tokenStart && strchr(delim, *tokenStart)) 
    {
        tokenStart++;
    }

    if (*tokenStart == '\0') 
    {
        input = NULL;
        return NULL;  // no tokens left
    }

    // Find end of token
    char* tokenEnd = tokenStart;
    while (*tokenEnd && !strchr(delim, *tokenEnd)) 
    {
        tokenEnd++;
    }

    if (*tokenEnd) 
    {
        *tokenEnd = '\0';   // terminate token
        input = tokenEnd + 1; // move pointer forward
    } else 
    {
        input = NULL;  // reached end of string
    }

    return tokenStart;
}

int main() 
{
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]", str);

    char* token = myStrtok(str, " ");  // split by space
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = myStrtok(NULL, " ");
    }

    return 0;
}