//

#include<stdio.h>
int main()
{
    char ch = 'A';
    char arr[8] = {0};
    int last_bit;

    for(int i = 0; i < 8; i++)
    {
        arr[i] = arr[i] & (~1);
    
        if(ch & 1 << i)
            last_bit = 1;
        else
            last_bit = 0;
        
        arr[i] = arr[i] | last_bit;
    }

    char ch1 = 0;
    for(int i = 0; i < 8; i++)
    {
        int decode = arr[i] & 1;
        
        ch1 =  ch  | (decode << i);
    }

    printf("Ch1 --> %c\n",ch1);
}