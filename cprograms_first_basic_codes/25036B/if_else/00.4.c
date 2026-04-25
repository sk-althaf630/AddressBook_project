#include <stdio.h>
int main ()
{
    char ch;


    printf( "Go outside and check is it raining?\nPress 'Y' for yes or 'n' for no\n");
    scanf("%c", &ch);

    if (ch == 'y')
    {
        printf("You can chill out, don't go fot classes\n");
        
    }
    else if(ch == 'n')
    {
        printf("Go to Classes\n");

    }
    else
    {

        printf("DON'T DO AGENE\n");
    }

    printf("Ending\n");

}