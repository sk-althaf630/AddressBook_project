//copying the two string and storing in first string without lossing old data
//sample input :- 1st string ->Hello
//                2nd string ->world
//sample output :- Helloworld
#include <stdio.h>
char *my_strcat(char *ptr1, char *ptr2)
{
    int i =0, j =0;
    while(ptr1[i] !='\0')
    {
        i++;
    }

    while(ptr2[j] !='\0')
    {
        ptr1[i] = ptr2[j];
        j++;
        i++;
    }
    ptr1[i] = '\0';
    return ptr1;
}

int main()
{
    char str1[100];
    printf("Enter the string1: ");
    scanf("%s", str1);

    char str2[100];
    printf("Enter the string2: ");
    scanf(" %[^\n]", str2);

    char* ret = my_strcat(str1,str2);
    printf("full string: %s\n", ret);
    return 0;
}