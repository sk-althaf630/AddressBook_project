/*WAP to check a number is palindrome and reverse
    sample input:- 121
    sample output:-121 and palindrome */

#include <stdio.h>
    int main()
    {
        int num;
        printf("Enter the number: ");
        scanf("%d", &num);
        
        int rem;
        int res = 0;
        int num2 = num;
        while(num > 0)
        {
            rem = num % 10;
            res = res * 10 + rem;
            num = num / 10;
        }
        printf("RES ---> %d\n", res);
        if(num2 == res)
        {
            printf("Given number is a palindrome.\n");
        }
        else
        {
            printf("Given number is a not palindrome.\n");
        }
        return 0;
    }