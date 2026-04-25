#include <stdio.h>
int main()
{
    FILE *fptr;
    if((fptr = fopen("new_file.txt", "w")) == NULL)
    {
        printf("not found\n");
    }
    char ch;
    while(ch = getc(fptr))
    {
        if(feof(fptr) || ferror(fptr))
        {
            break;
        }
        putc(ch,stdout);
    }
    printf("\n");
    fclose(fptr);
}