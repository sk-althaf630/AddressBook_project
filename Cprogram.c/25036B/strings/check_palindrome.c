//WAP to check if the string is palindrome or not.
// sample input :- madam
// sample out :- yes, it is a palindarame.

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    printf("Enter the string : ");
    scanf("%[^\n]", str);

    char ptr[100];
    strcpy(ptr, str);//copy original string.
    int len = strlen(ptr);

    //reverse the string in ptr
    for(int i = 0; i < len/2; i++)
    {
        char temp = ptr[i];
        ptr[i] = ptr[len -i- 1];
        ptr[len - 1 - i] = temp;
    }

    if(strcmp(str, ptr) != 0)
    {
        printf("Not a palindrome\n");
    }
    else
    {
        printf("Yes, it is a palindrome\n");
    }

    return 0;
}