//15.Remove all single line comments from the given .c file.
#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp, *temp;
    char buffer[1024];

    // Open source file
    if ((fp = fopen("main_file.c", "r")) == NULL) {
        perror("Error opening main_file.c");
        return 1;
    }

    // Open temporary file
    if ((temp = fopen("temp_file.c", "w")) == NULL) {
        perror("Error opening temp_file.c");
        fclose(fp);
        return 1;
    }

    // Process each line
    while (fgets(buffer, sizeof(buffer), fp)) {
        char *commentPos = strstr(buffer, "//"); // find start of comment
        if (commentPos != NULL) {
            *commentPos = '\0'; // truncate line at comment
        }

        // Remove trailing spaces/tabs before writing
        int len = strlen(buffer);
        while (len > 0 && (buffer[len-1] == ' ' || buffer[len-1] == '\t' || buffer[len-1] == '\n')) {
            buffer[--len] = '\0';
        }

        if (len > 0) {
            fprintf(temp, "%s\n", buffer);
        } else {
            fprintf(temp, "\n"); // preserve blank line
        }
    }

    fclose(fp);
    fclose(temp);

    // Replace original file with cleaned file
    remove("main_file.c");
    rename("temp_file.c", "main_file.c");

    printf("All single-line comments removed successfully.\n");
    return 0;
}