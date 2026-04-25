#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void my_exit(void);
void test();

char *ptr;
int main()
{
    atexit(my_exit);//it act like an alarm
    ptr = malloc(10 *sizeof(char));
    strcpy(ptr, "virat");
    test();
    printf("tuesday\n");
}

void test()
{
    printf("hello world\n");
    printf("%s\n", ptr);
}

void my_exit(void)
{
    printf("inside my_exit\n");
    free(ptr);
}