#include <stdio.h>
int main()
{
    FILE *fp;
    if((fp = fopen("text.txt" , "r")) == NULL)
    {
        printf("not found\n");
        return 0;
    }
    //printf("001 ---> the file pointer is pointing to %ld\n", ftell(fp));
    int i = 1;
    char ch;
    while(ch = getc(fp) != EOF);
    {
        if(ch == 'c')
    }
    printf("---> the file pointer is pointing to %ld\n", ftell(fp));
    rewind(fp);
        printf("---> the file pointer is pointing to %ld\n", ftell(fp));
}