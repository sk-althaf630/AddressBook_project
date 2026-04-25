#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr = (int *) calloc(5, sizeof(int));
    for(int i = 0; i < 5; i++)
    {
        scanf("%d", &ptr[i]);
    }

    for(int i = 0; i < 5; i++)
    {
        printf("%d\n", ptr[i]);//*ptr++ it also work
        //printf("%d ", *ptr++);
    }
    free(ptr);
    //after freed memory if axis that memory it gives undefind behaveor
    //this type of pointer is called dangllying pointer
    /*for(int i = 0; i < 5; i++)
    {
        printf("%d\n", ptr[i]);
    }*/
   printf("hello\n");
   return 0;
}