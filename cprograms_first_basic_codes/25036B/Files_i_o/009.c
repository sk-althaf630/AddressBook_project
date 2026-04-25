#include <stdio.h>
int main()
{
    FILE *fp;
    int a = 45;
    char ch = '+';
    float f = 56.7;
    char str[] = "is";
    double d = 345.435;
    if((fp = fopen("today01.txt", "w+")) == NULL)
    {
        fprintf(stderr,"file is not found");
        return 0;
    }
    fprintf(fp,"%d %c %f %s %lf", a, ch, f,str,d);
    fclose(fp);

}