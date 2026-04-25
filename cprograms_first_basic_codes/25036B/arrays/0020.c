#include <stdio.h>
int main()
{
    char str[4] = {"hello", "hi" , "are"};
    //for(int i = 0; i < 4; i++)
    //{
     //   scanf("%s", str[i]);
   // }
    printf("%s\n", str[0]);
    printf("%s\n", str[1]);
    printf("%s\n", str[2]);

    //str[0] = "chaat"; not allowed trying to change the vase address of th 2st 1D array
    str[0][0] = "H";
    str[2][2] = "w";
    printf("%s\n", str[0]);
    printf("%s\n", str[1]);
    printf("%s\n", str[2]);
    printf("%s\n", str[3]);

    strcpy(str[0], "rohit");

    printf("%s\n", str[0]);
    printf("%s\n", str[1]);
    printf("%s\n", str[2]);
    printf("%s\n", str[3]);
}