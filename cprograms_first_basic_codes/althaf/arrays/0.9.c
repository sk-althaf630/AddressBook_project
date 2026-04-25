/*WAP to check a number is palindrome and reverse by arrays
    sample input:- 121
    sample output:-121 and palindrome */

#include <stdio.h>
int main()
{
    int size;
    printf("Enter the array of size: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the array elements: ");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < size; i++)
    {
        int num = arr[i];
        int revs = 0;
        int rem;
        while(num != 0)
        {
            rem = num % 10;
            revs = revs * 10 + rem;
            num = num / 10;
        }
        if(revs == num)
        {
            printf("%d == %d ---> palindrome\n", revs, num);
        }
        else
        {
            printf("%d == %d ----> Not a palindrome\n", revs, num);
        }
    }
    return 0;
}