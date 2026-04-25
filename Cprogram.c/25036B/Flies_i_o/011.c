//10.Print Last Line of the file.
#include <stdio.h>

int main() {
    FILE *fp;
    char buffer[256];
    char lastLine[256];

    fp = fopen("which_line.txt", "r");
    if (fp == NULL) {
        perror("File not found");
        return 1;
    }

    // Read each line and overwrite lastLine
    while (fgets(buffer, sizeof(buffer), fp))
    {
        // Copy current line into lastLine
        snprintf(lastLine, sizeof(lastLine), "%s", buffer);
    }
    // Read each line until the end
   /* while (fgets(buffer, sizeof(buffer), fp)) 
    {
        // Copy current line into lastLine
        // (this way lastLine always holds the most recent line read)
        int i = 0;
        while (buffer[i] != '\0') {
            lastLine[i] = buffer[i];
            i++;
        }
        lastLine[i] = '\0';  // add string terminator
    }*/


    fclose(fp);

    // Print the last line after loop ends
    printf("Last line of the file:\n%s", lastLine);

    return 0;
}