#include <stdio.h>
int main()
{
    FILE *fp;
    int a = 45,b;
    char ch = '+',ch1;
    float f = 56.7,f1;
    char str[] = "is",str1[10];
    double d = 345.435,d1;
    if((fp = fopen("today01.txt", "w+")) == NULL)
    {
        fprintf(stderr,"file is not found\n");
        return 0;
    }
    int ret1 = fprintf(fp,"%d %c %f %s %lf", a, ch, f,str,d);
    fseek(fp,0,SEEK_SET);//same as rewind(fp)
    int ret= fscanf(fp,"%d %c %f %s %lf", &b, &ch1, &f1, str1, &d1);
    printf("%d %c %f %s %lf\n", b,ch1,f1,str1,d1);
    printf("fp return--> %d\nfp return ---> %d\n", ret1, ret);
    fclose(fp);
}