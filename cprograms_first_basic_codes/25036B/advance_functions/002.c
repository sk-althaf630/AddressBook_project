//wap to print sum of two numbers  with commend line argument
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        printf("Invalid no of argument\n");
        return 1;
    }
    int sum = atoi(argv[1])+atoi(argv[2]);
    printf("%d\n", sum);
    return 0;
}