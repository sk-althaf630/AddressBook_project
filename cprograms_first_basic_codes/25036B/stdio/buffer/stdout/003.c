#include <stdio.h>
#include<unistd.h>
int main()
{
    char str[] = "1";
    setbuf(stdout,NULL);
    while (1)
    {
        fprintf(stdout,"%s",str);
        sleep(1);
    }
    
}