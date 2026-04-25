//files modes
#include<stdio.h>
int main()
    {
        FILE *fptr;
        if((fptr=fopen("text.txt","w+"))==NULL)
        {
            printf("File not found\n");
            return 0;
        }
        char ch;
        fputc('S',fptr);
        fputc('A',fptr);
        fputc('L',fptr);
        fputc('A',fptr);
        fputc('A',fptr);
        fputc('A',fptr);
        fputc('A',fptr);
        fputc('R',fptr);
        rewind(fptr); // brings the file pointer to the beginning of the file
        while((ch = fgetc(fptr)) !=EOF)
        {
            fputc(ch,stdout);
        }

    }