//14.Print the longest line of the .txt file.
#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char buffer[1024];       // temporary buffer for each line
    char longest[1024];      // store the longest line
    int maxLen = 0;

    // Open file
    if ((fp = fopen("main_file.txt", "r")) == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read line by line
    while (fgets(buffer, sizeof(buffer), fp)) {
        int len = strlen(buffer);
        if (len > maxLen) {
            maxLen = len;
            strcpy(longest, buffer);
        }
    }

    fclose(fp);

    if (maxLen > 0) {
        printf("Longest line (%d characters):\n%s", maxLen, longest);
    } else {
        printf("File is empty.\n");
    }

    return 0;
}