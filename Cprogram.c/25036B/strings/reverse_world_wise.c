//WAP reverse the string word wise.
//sample input :- hello world
//sample output :- world hello
#include <stdio.h>
#include <string.h>

// Function to reverse a portion of the string
void reverse(char *str, int start, int end) {
    while (start < end) 
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() 
{
    char str[100];
    printf("Enter the string: ");
    scanf("%[^\n]", str);

    int len = strlen(str);

    // Step 1: Reverse the entire string
    reverse(str, 0, len - 1);

    // Step 2: Reverse each word back to correct order
    int start = 0;
    for (int i = 0; i <= len; i++) 
    {
        if (str[i] == ' ' || str[i] == '\0') 
        {
            reverse(str, start, i - 1);
            start = i + 1;
        }
    }

    printf("Reversed word-wise string: %s\n", str);
    return 0;
}