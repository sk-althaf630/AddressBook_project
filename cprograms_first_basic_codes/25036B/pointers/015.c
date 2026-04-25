#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr = (int *) malloc(5);
    //int *ptr1 =(int *) malloc(5 *sizeof(int));
    for(int i = 0; i < 5; i++)
    {
        scanf("%d", &ptr[i]);
    }

    for(int i = 0; i < 5; i++)
    {
        printf("%d ", ptr[i]);//*ptr++ it also work
        //printf("%d ", *ptr++);
    }
    free(ptr);
}