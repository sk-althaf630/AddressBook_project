#include <stdio.h>
int main()
{
    char *str[4] = {"hello" , "how", "are" , "you"};
    printf("%s\n", str[0]);//
    printf("%s\n", str[1]);
    printf("%s\n", str[2]);
    printf("%s\n", str[3]);

    str[0] = "what";// it is posible becouse of we are chenging the adderss of the *str pointing.
    printf("%s\n", str[0]);

    //str[0][0] = 'H'; //it not allowed trying to modify this means it give in runtime segmentation falut error
}