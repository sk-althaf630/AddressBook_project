#include <stdio.h>

int main()
{
    char ch1;
    printf("Enter the 1player name: ");
    scanf("%c", &ch1);

    char ch2;
    printf("Enter the 2player name: ");
    scanf("%c", &ch2);

    for(int i = 0;i <= 13; i++)
    {
        int n1;
        printf("%c select chocolates: ", ch1);
        scanf("%d", &n1);

        int n2;
        printf("%c select chocolates: ", ch2);
        scanf("%d", &n2);
        int chocolates = 13;
        int temp;

        switch(n1)
        {
            case 1:
            temp = chocolates - n1;
            break;

            case 2:
            temp = chocolates - n1;
            break;

            case 3:
            temp = chocolates - n1;
            break;

            default:
            printf("Invalid option");
        }
        printf("You have selected a chocolates remining %d", temp);
        printf("\n");

        switch(n2)
        {
            case 1:
            temp = chocolates - n2;
            break;

            case 2:
            temp = chocolates - n2;
            break;

            case 3:
            temp = chocolates - n2;
            break;

            default:
            printf("Invalid option");
        }
        printf("You have selected a chocolates remining %d", temp);
        printf("\n");
    }
}