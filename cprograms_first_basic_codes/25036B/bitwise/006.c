#include <stdio.h>
int main()
{
    unsigned char iter = 0xFF;
    int count;
    for(count = 0;iter!=0; iter>>=1)
    {
        if(iter & 1)
        {
            count++;
        }
    }
    printf("%d\n", count);
}