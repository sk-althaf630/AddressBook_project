//3.Print the content of the .txt file in reverse order.
#include <stdio.h>
int main()
{
    FILE *fp;
    char ch;
    long pos;

    if((fp = fopen("exeamp.text" , "r")) == NULL)
    {
        perror("file is not found\n");
        return 1;
    }

    fseek(fp,0,SEEK_END);//skip the all charactor and reaches to end of the charactor
    pos = ftell(fp);//ftell() return the possition of the end charactor(not for geting the perfect possition (pos - 1))
    //assum you have hello count is 5 a[4] = 0 so pos -1;

     while(pos > 0)
    {
        pos--;//in file information will store in "hello\n EOF" EOF is not a charactor.
        fseek(fp, pos, SEEK_SET);
        ch = fgetc(fp);
        putchar(ch);
    }

    fclose(fp);
    return 0;
}