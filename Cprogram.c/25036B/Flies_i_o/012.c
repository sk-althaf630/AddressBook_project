//11.Scan n integers from user and store in .txt file (each in new line).
#include <stdio.h>

int main() 
{
    FILE *fp;
    int n, num;

    printf("Enter how many integers you want to store: ");
    scanf("%d", &n);

    fp = fopen("numbers.txt", "w");  // open file in write mode
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        fprintf(fp, "%d\n", num);  // write each integer on a new line
    }

    fclose(fp);
    printf("Integers successfully stored in numbers.txt\n");

    return 0;
}