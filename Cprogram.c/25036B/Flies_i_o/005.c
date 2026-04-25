//4.Print the content of the .txt file in continu order.
#include <stdio.h>
int main()
{
    FILE *fp;
    char ch;
    long pos;

    if((fp = fopen("contine.txt", "r")) == NULL)
    {
        perror("file is not found\n");
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    pos = ftell(fp);

    for(int i = 0; i < pos; i++ )
    {
        fseek(fp, i, SEEK_SET);
        ch = fgetc(fp);
        putchar(ch);
    }

    fclose(fp);
    return 0;
}