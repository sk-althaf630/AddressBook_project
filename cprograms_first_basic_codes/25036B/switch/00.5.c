#include <stdio.h>
int main()
{
    printf("------>welcome<-------"):
    printf("Enter the what you  want to order:\n");
    printf("1.pizza\n2.coffee\n3.Dosa\n4.masala Dosa\n5.Idli\n");
    int option;
    scanf("%d", &option);

    switch(option)
    {
        case 1:
        printf("Orded pizza\n");
        break;

        case 2:
        printf("Orded coffee\n");
        break;

        case 3:
        printf("Orded Dosa\n");
        break;

        case 4:
        printf("Orded masala Dosa\n");
        break;

        case 5:
        printf("Orded idli\n");
        break;
    }
    printf("thanku")
    return 0;
}