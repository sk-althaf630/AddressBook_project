//1.Print the data of .txt file
#include <stdio.h>
int main()
{
    FILE *fp;
    if((fp = fopen("file.txt", "r"))== NULL)
    {
        perror("file is not found\n");
        return 1;
    }

    char ch;
    while((ch = fgetc(fp)) !=EOF)
    {
        putchar(ch);
    }
    
    fclose(fp);
    return 0;
}