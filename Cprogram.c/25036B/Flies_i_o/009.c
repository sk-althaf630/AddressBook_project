//8.Count the number of lines in the file.
#include <stdio.h>
{
    FILE *fp;
    char ch;
    int line_count = 0;

    if((fp = fopen("line_count.txt" , "r")) == NULL)
    {
        perror("file is not found\n");
        return 1;
    }

    while((ch = fgetc(fp)) != EOF)
    {
        if(ch == ' ')
        {
            line_count++;
        }
    }

    // If file is not empty, add 1 for the last line (no trailing newline)
    if(line_count == 0 && !feof(fp))
    {
        line_count = 0;
    }
     printf("Number of lines in file: %d\n", lineCount);
     fclose(fp);
     return 0;
}