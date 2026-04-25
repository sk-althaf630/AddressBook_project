//wap to print sum of n numbers  with commend line argument
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        printf("Invalid no of argument\n");
        return 1;
    }

    int sum = 0;
    for(int i = 0; i < argc; i++)
    {
        sum = sum +atoi(argv[i]);
    }
    printf("sum = %d\n", sum);
    return 0;
}