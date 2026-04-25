#include <stdio.h>
int fun()
{
    printf("hello world\n");
    return 264;
}
int main()
{
    printf("main ---> %p\n", main);
    printf("&main ----> %p\n", &main);
    printf("fun ---> %p\n", fun);
    printf("&fun ---> %p\n", &fun);

    printf("fun ---> %d\n", fun());

}