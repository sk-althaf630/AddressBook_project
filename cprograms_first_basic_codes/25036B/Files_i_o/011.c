#include <stdio.h>
int main()
{
    FILE *fp;
    if((fp = fopen("tody02.txt","w+"))==NULL)
    {
        fprintf(stderr,"file is not found\n");
        return 1;
    }
    int num1 = 45, num2 =18, num3, num4;
    fwrite(&num1,sizeof(num1),1,fp);
    fwrite(&num2,sizeof(num2),1,fp);
    rewind(fp);
    fread(&num3,sizeof(num3),1,fp);
    fread(&num4,sizeof(num4),1,fp);
    printf("name is %d---name is %d\n", num3, num4);
}