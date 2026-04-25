#include <stdio.h>
int main()
{
    FILE *fptr;
   if((fptr = fopen("file.txt", "w+")) == NULL)
    {
        printf("file is not found\n");
        return 0;
    }
    char ch;
    fputc('r',fptr);
    fputc('a',fptr);
    fputc('i',fptr);
    fputc('n',fptr);
    fputc('y',fptr);
    rewind(fptr);
    while((ch = fgetc(fptr)) != EOF)
    {
        fputc(ch,stdout);
    }
}