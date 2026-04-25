#include <stdio.h>
int main()
{
    int option, quantity;
    float total=0;
    char ch;

    char S=20;
    char M=28;
    char L=32;

    printf("1.COTTON SHIRT---299\n2.COTTON PANTS---599\n3.INNERWEAR---99\n4.PAYMENT TYPE1.onilin,2.hand case\n5.EXITE");

    do
    {
        printf("\n------------------------------\n");
        printf("Available Sizes:\n");
        printf("S - Small\n", S);
        printf("M - Medium\n", M);
        printf("L - Large\n", L);
        printf("--------------------------------\n");
  

        printf("Enter the size: %C\n");
        scanf("%c", &ch);

        printf("Enter the amount: %d\n");
        scanf("%d", &option);
        if(option>=1 && option<=5)
        {
            printf("Enter the quantity: ");
        }

        switch(option)
        {
            case 1:
            if(ch==S||ch==M||ch==L)
            {
                printf("order placed: %d\nSize is: %c\nAmount is: %d\n", ch, quantity);
                total+=quantity*299;
            }
            else
            {
                printf("Invalid size for Cotton Shirts: %c. Please try again.\n", ch, quantity);
            }
            break;
            case 2:
            if(ch==S||ch==M||ch==L)
            {
                printf("order placed: %d\nSize is: %c\nAmount is: %d\n", ch, quantity);
                total+=quantity*599;
            }
            else
            {
                printf("Invalid size for Cotton Shirts: %c. Please try again.\n", ch, quantity);
            }
            break;
            case 3:
            if(ch==S||ch==M||ch==L)
            {
                printf("order placed: %d\nSize is: %c\nAmount is: %d\n", ch, quantity);
                total+=quantity*99;
            }
            else
            {
                printf("Invalid size for Cotton Shirts: %c. Please try again.\n", ch, quantity);
        
            }
            break;
            case 4:
            switch(option)
            {
                case 1:
                printf("Her is the QR.");
                break;
                case 2:
                printf("There is 10 present discount on ofline payment.");
                break;
            }
            break;
            case 5:
            printf("\n-----EXITING----\n");
            printf("Thank you for using this app! Your total was: %g\n", total);
            
            default:
            printf("SORRY WE CON'T COPERATE WITH THIS OPTION PLEASE TRY AGAIN LATER\n");
        }
        

    }while(option>3);

    printf("\n----->BILLING SECTION<-----\n");
    printf("The Total amount is: %g\n", total);
    printf("\nThanking for Using thi APP\n");
}