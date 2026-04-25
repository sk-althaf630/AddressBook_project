#include <stdio.h>
int main()
{
    char arr[8] = {0};
    char ch = 'A';

    for(int i = 0; i < 8; i++)
    {
        arr[i] = arr[i] &(~1);//for clearing bit
        int get = (ch & (1<<i)) >> i;

        arr[i] = arr[i] | get;
    }

    for(int i = 0; i < 8; i++)
    {
        for(int j = 7; j >= 0; j--)
        {
            printf("%d", (arr[i] >> j) & 1);
        }
        printf("\n");
    }

    

    return 0;
}