#include <stdio.h>
int main()
{
    int i = 10;
    while(i--)
    {
        fprintf(stderr,"hello");
        fprintf(stdout,"world");
        sleep(1);
    }
}