//wap to print enveronmental variable
#include <stdio.h>
#include <string.h>
int main(int argc, char * argv[], char * envp[])
{
    int i = 0;
    char *var,*val;
    if(argc != 2)
    {
        printf("not enough arguments\n");
        return 1;
    }

    while(envp[i] != NULL)
    {
        var = strtok(envp[i], "=");
        if(!strcmp(argv[1], var))
        {
            val = strtok(NULL, "=");
            break;
        }
        i++;
    }

    if(envp[i] != NULL)
    {
        printf("%s\n", val);
    }
    else
    {
        printf("variable not foung --> %s\n", argv[i]);
    }

}