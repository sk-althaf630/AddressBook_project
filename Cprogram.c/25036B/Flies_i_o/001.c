#include<stdio.h>
int main()
{
    FILE *fptr;

    if((fptr = fopen("file.text", "w+")) == NULL)
    {
        printf("File is not found\n");
        return 0;
    }
    char ch;
    fputc('r',fptr);
    fputc('a',fptr);
    fputc('i',fptr);
    fputc('n',fptr);
    fputc('y',fptr);
    fputc(' ',fptr);
    fputc('d',fptr);
    fputc('a',fptr);
    fputc('y',fptr);
    while(ch == fgetc(fptr) != EOF)
    {
        fputc(ch,stdout);
    }
}