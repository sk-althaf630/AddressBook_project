#include <stdio.h>
struct student
{
    /* data */
    int id;
    char name[20];
    char address[60];
};

int main()
{
   struct student d1 = {45, "althaf", "manikanta"}, d2;
   FILE *fp;
   fp = fopen("today03.txt","w+");
   fwrite(&d1,sizeof(d1),1,fp);
   rewind(fp);
   fread(&d2,sizeof(d2),1,fp);
   
}