//5.Find the size of the given file.
#include <stdio.h>
int main()
{
    FILE *fp;
    long size;

    if((fp = fopen("size.txt" , "r")) == NULL)
    {
        perror("file is not found\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);

    printf("size of this file is %ld bytes\n", size);

    fclose(fp);
    return 0;
}