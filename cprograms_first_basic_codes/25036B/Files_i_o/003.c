#include<stdio.h>
int main()
{
    FILE *fp1, *fp2;
    if((fp1=fopen("text.txt","r"))==NULL)
    {
        fprintf(stderr,"File text.txt not found\n");
        return 0;
    }
    if((fp2=fopen("text_copy.txt","w"))==NULL)
    {
        fprintf(stderr,"File text.txt not found\n");
        return 0;
    }
    char ch;
    while((ch=getc(fp1))!=EOF)
    {
        putc(ch,fp2);
    } 
    fclose(fp1);
    fclose(fp2);
}