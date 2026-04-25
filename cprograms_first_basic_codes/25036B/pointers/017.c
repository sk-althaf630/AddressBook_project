#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr = (int*)realloc(NULL,5 *sizeof(int));//equivalent to malloc(size)
    char *ptr1 = malloc(5 *sizeof(char));
    printf("%p\n", ptr);
    printf("%p\n", ptr1);

    for(int i = 0; i < 5; i++)
    {
        ptr[i] = 45;
    }
    for(int i = 0; i < 5; i++)
    {
        ptr1[i] = 'v';
    }
    for(int i = 0; i < 5; i++)
    {
      printf("%d\t", ptr[i]);
    }
    printf("\n");

    for(int i = 0; i < 5; i++)
    {
       printf("%c\t", ptr1[i]);
    }
    printf("\n");
    
    /*when we are useing the realloc it should collact it back in the same pointer only, if it have space means it 
    will continu and it does not have space means it copys the hole contant and copys in anothe place*/

    ptr =(int *)realloc(ptr,10*sizeof(int));
    ptr1 = (char*)realloc(ptr1,7*sizeof(char));

    for(int i = 0; i < 5; i++)
    {
      printf("%d\t", ptr[i]);
    }
    printf("\n");

    for(int i = 0; i < 5; i++)
    {
       printf("%c\t", ptr1[i]);
    }
    printf("\n");

    ptr = realloc(ptr,0);//equivalent to free(ptr);
    free(ptr1);
}