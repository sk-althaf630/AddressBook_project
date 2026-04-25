//12.Scan n names from user and store in .txt file (each in new line).
#include <stdio.h>

int main() 
{
    FILE *fp;
    int n, i;
    char name[100];

    printf("Enter how many names you want to store: ");
    scanf("%d", &n);

    fp = fopen("names.txt", "w");  // open file in write mode
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    printf("Enter %d names:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%s", name);              // read a single word name
        fprintf(fp, "%s\n", name);      // write each name on a new line
    }

    fclose(fp);
    printf("Names successfully stored in names.txt\n");

    return 0;
}