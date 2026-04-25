//wap to print the envp varibles in display
#include <stdio.h>

int main(int argc, char* argv[], char* envp[])
{
    int i = 0;
    while(envp[i] != NULL)
    {
        printf("%s\n", envp[i]);
        i++;
    }
}