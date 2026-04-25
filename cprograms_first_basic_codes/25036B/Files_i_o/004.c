#include <stdio.h>
int main()
{
    FILE *fp;
    if((fp = fopen("text.txt" , "r")) == NULL)
    {
        printf("not found\n");
        return 0;
    }
    printf("001 ---> the file pointer is pointing to %ld\n", ftell(fp));
    char ch;
    while(ch = getc(fp) != EOF);
    printf("---> the file pointer is pointing to %ld\n", ftell(fp));
    rewind(fp);
        printf("---> the file pointer is pointing to %ld\n", ftell(fp));
}