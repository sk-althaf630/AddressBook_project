#include <stdio.h>
int main()
{
    FILE *fptr;
    fptr = fopen("file.txt", "w");
    char ch = fgetc(fptr);//trying to read in write mode. it should be a error
    if(ferro(fptr))
    {
        printf("error has occured while reading from file\n");

    }
    clearror(fptr);
    if(ferror(fptr))
    {
        printf("error has occured while reading form the file\n");
    }
    else
    {
        printf("clearer cleared the error indicator\n");
    }
}