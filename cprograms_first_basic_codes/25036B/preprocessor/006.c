#include <stdio.h>
#define swap(a,b,type)\
{\
type  temp = a;\
a= b;\
b = temp; \
}
int main()
{
    int a= 10, b = 20;
    printf("Before swap --> %d %d\n", a, b);
    swap(a,b,int);
    printf("After sawp ---> %d %d\n", a, b);

    float c = 3.8, d = 5.9;
    printf("Before swap ----> %g %g\n", c, d);
    swap(c,b,float);
    printf("After swap ----> %g %g\n", c, d);

    double g = 3.44, f = 5.66;
    printf("Before swap ----> %g %g\n", g, f);
    swap(g,f,double);
    printf("After swap ----> %g %g\n", g, f);

    return 0;

}
                                                                 

