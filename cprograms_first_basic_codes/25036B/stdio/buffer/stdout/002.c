#include <stdio.h>
#include<unistd.h>
int main()
{
    char mybuff[10];
    char str[] = "1";
    setbuffer(stdout,mybuff,sizeof(mybuff));
    while (1)
    {
        fprintf(stdout,"%s",str);
        sleep(1);
    }
    
}