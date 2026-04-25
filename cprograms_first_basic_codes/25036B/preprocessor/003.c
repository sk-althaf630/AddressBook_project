#include<stdio.h>
#define mptr int * //macro
typedef int * tptr; //typedef

int main()
{
    mptr ptr1, * ptr2;
    tptr ptr3, ptr4;
    printf("%lu %lu", sizeof(ptr1), sizeof(ptr2));
    printf("%lu %lu", sizeof(ptr3), sizeof(ptr4));
}

#include<stdio.h>
#define msg "hello world" //MSG or msg both are same
int main()
{
    printf("%s\n", msg);
    printf(msg);//both are printf are same.
}

/*#include<stdio.h>
#define MUL(a, b) (a)*(b)
int main()
{
    printf("%d\n", MUL(5+1,6+1));

    #undef MUL //undefining
}*/