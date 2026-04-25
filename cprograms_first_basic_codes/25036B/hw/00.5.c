#include <stdio.h>
int main()
{
    int option,quantity;
    float total=0;

    printf("\n------>WELCOME TO RESTARNT<------\n");
    printf("To the Menu order system!\n");
    printf("1.PIZZA---RS.100\n2.COFFEE---RS.20\n3.DOSA---RS.25\n4.MASALA DOSA---RS.30\n5.IDLI---10\n6.EXIT\n");
    do
    {
        printf("Enter the number of your choices: \n");
        scanf("%d", &option);
        if(option>=1 && option<=6)
        {
            printf("Enter th quantity: \n");
            scanf("%d", &quantity);
        }
        else
        {
            printf("Thanking for visiting\n");
        }

        switch (option)
        {
            case 1:
            printf("Add Pizza to order:%d\n",quantity);
            total+=quantity*100;
            break;
            case 2:
            printf("Add Coffee to order:%d\n",quantity);
            total+=quantity*20;
            break;
            case 3:
            printf("Add Dosa to order:%d\n",quantity);
            total+=quantity*25;
            break;
            case 4:
            printf("Add Masala_Dosa to order:%d\n",quantity);
            total+=quantity*30;
            break;
            case 5:
            printf("Add Idli to order:%d\n",quantity);
            total=quantity*10;
            break;

        default:
            printf("EXITING\n");
            break;
        }

    } while (option<6);

    printf("\nOrder is Finished\n");
    printf("Your final bill is: %g\n", total);
    printf("Thank you for your order\n");
    return 0;
    
}