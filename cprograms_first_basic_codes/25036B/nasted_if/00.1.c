# include <stdio.h>
int main()
{
    int num;
    printf("Enter the numbers: ");
    scanf("%d", &num);
    
    if (num %2)//num is odd
    {
        if (num > 0)//num is positive
        {
            printf("%d is positive and odd\n", num);
        }
        else//num is negative
        {
            printf("%d is negative and odd\n", num);
        }
    }
    else//num is even
    {
        if (num > 0)//num is positive
        {
            printf("%d is positive and even\n", num);
        }
        else//num is negetive
        {
            printf("%d is negetive and even\n", num);
        }
    }
    return 0;
}