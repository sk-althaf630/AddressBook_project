/* WAP of manul of working of strstr
   sample:- hello world and world
   sample output:-yes matched*/
#include <stdio.h>
char *my_strstr(char *main, char *sub)
{
    for(int i = 0; main[i] != '\0'; i++)
    {
        int j = 0;
        while(sub[j] != '\0' && main[i + j] == sub[j])
        {
            j++;
        }
        if (sub[j] == '\0')
        {
            return &main[i];//match found
        }
    }
    return NULL;
}
int main()
{
    char str[100];
    printf("Enter the main string: ");
    scanf("%[^\n]", str);

    char sub[100];
    printf("Enter the sub string: ");
    scanf(" %[^\n]", sub);

    char *result = my_strstr(str,sub);

    if(result == NULL)
    {
        printf("the sub_string is not foundint main_string: %s\n", result);
    }
    else
    {
        printf("The sub_string is matched to the main_string: %s\n", result);
    }
}