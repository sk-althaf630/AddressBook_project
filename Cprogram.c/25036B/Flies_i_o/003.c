//2. Create a copy of 1.txt as 2.txt file.
#include <stdio.h>
int main()
{
    FILE *sourc;
    if((sourc = fopen("1.txt", "r")) == NULL)
    {
        perror("file is not found\n");
        return 1;
    }

    FILE *dest;
    if((dest = fopen("2.txt", "w")) == NULL)
    {
        perror("file is not found\n");
        fclose(sourc);//any error occure this file should close
        return 2;
    }

    char ch;
    //reading the charactor by charactor form sourc
    while((ch = fgetc(sourc)) != EOF)
    {
        fputc(ch,dest);//writeing charactor by charactor to dest
    }
    
    printf("File successfully readed one file to an othe file\n");
    
    fclose(sourc);
    fclose(dest);
    return 0;
}