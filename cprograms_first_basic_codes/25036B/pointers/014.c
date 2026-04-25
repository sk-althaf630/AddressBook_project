#include<stdio.h>
void swap(void*ptr1,void*ptr2,int size);
struct student
{
    int id;
    char name[100];
    char add[100];
};
int main()
{
   int a=2435678,b=2345634;
   short s1=324,s2=657;
   char ch1='A' ,ch2='B';
   float f1=13.2 ,f2=34.5;
   double d1=23456.123 ,d2=45667.234;
   struct student st1={45,"rohit","mumbai"},st2={18,"virat","rcb"};

   printf("Before swap integer %d %d\n",a,b);
   swap(&a,&b ,sizeof(int));
   printf("After swap integer %d %d\n",a,b);

   printf("Before swap short %hd %hd\n",s1,s2);
   swap(&s1,&s2 ,sizeof(short));
   printf("After swap short %hd %hd\n",s1,s2);

   printf("Before swap char %c %c\n",ch1,ch2);
   swap(&ch1,&ch2 ,sizeof(char));
   printf("After swap char %c %c\n",ch1,ch2);

   printf("Before swap float %f %f\n",f1,f2);
   swap(&f1,&f2 ,sizeof(float));
   printf("After swap float %f %f\n",f1,f2);

   printf("Before swap double %lf %lf\n",d1,d2);
   swap(&d1,&d2 ,sizeof(double));
   printf("After swap double %lf %lf\n",d1,d2);

   printf(" Before swaping the structure str1--> %d %s %s str2--> %d %s %s \n",st1.id,st1.name,st1.add,st2.id,st2.name,st2.add);
   swap(&st1,&st2,sizeof(struct student));
   printf(" After swaping the structure str1--> %d %s %s str2--> %d %s %s \n",st1.id,st1.name,st1.add,st2.id,st2.name,st2.add);
   return 0;


}
void swap(void *ptr1,void*ptr2,int size)
{
    for(int i=0;i<size;i++)
    {
        char temp=*(char*)ptr1;
        *(char*)ptr1=*(char*)ptr2;
        *(char*)ptr2=temp;
        (char*)ptr1++;
        (char*)ptr2++;
    }
}