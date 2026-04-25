/*


*/

#include <stdio.h>

int my_strcmp(char *s1, char *s2, int s3)
{
    int i = 0;
    while(s1[i] < s1[s3] !='\0' && s2[i] < s2[s3])
    {
        if(s1[i] == s2[i] || s1[i] == (s2[i] + 32) || (s1[i] + 32) == s2[i])
        {
            return s1[i] - s2[i];
        }
        i++;
        return s1[i] - s2[i];
    }
}
int main()
{
    char str1[100];
    char str2[100];
    
    printf("enter the first string: ");
    scanf("%[^\n]", str1);

    printf("enter the scond string: ");
    scanf(" %[^\n]", str2);

    int str3;
    printf("enter the compration number: ");
    scanf(" %d", &str3);

    int res = my_strcmp(str1,str2,str3);
    if(res < 0)
    {
        printf("str1 < str2\n");
    }
    else if(res > 0)
    {
        printf("str1 > str2\n");
        
    }
    else
    {
        printf("str1 == str2\n");
    }
}