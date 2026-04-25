#include <stdio.h>
int main()
{
    int option;
    int total_cost=0;

    int pizza=100;
    int coffee=15;
    int Dosa=25;
    int Masala_Dosa=30;
    int Idli=10;

    printf("\n------>WELCOME<------\n");
    printf("To the Menu order system!\n");
    do
    {
        printf("\n------>MENU<------\n");
        printf("Current Total:Rs. %d\n", total_cost);
        printf("1.Pizza Price(Rs.%d)\n", pizza);
        printf("2.Coffee Price(Rs.%d)\n", coffee);
        printf("3.Dosa Price(Rs.%d)\n", Dosa);
        printf("4.Masala Dosa Price(Rs.%d)\n", Masala_Dosa);
        printf("5.Idli Price(Rs.%d)\n", Idli);
        printf("6.Finish order and Pay\n");

        printf("Enter the what you  want to order:\n");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
            printf("Add Pizza to order.\n");
            total_cost=total_cost+pizza;
            break;
            case 2:
            printf("Add Coffee to order.\n");
            total_cost=total_cost+coffee;
            break;
            case 3:
            printf("Add Dosa to order.\n");
            total_cost=total_cost+Dosa;
            break;
            case 4:
            printf("Add Masala_Dosa to order.\n");
            break;
            case 5:
            printf("Add Idli to order.\n");
            total_cost=total_cost+Idli;
            break;

            case 6:
            break;

        default:
        printf("Invalid choice (%d). please select an option from 1 to 6.\n", option);
            break;
        }

    } while (option<6);

    printf("\nOrder is Finished\n");
    printf("Your final bill is: %d\n", total_cost);
    printf("Thank you for your order\n");
    return 0;
    
}