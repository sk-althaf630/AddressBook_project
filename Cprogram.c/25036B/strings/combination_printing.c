//wap to find the combination of the string
/*sampleinput:- abc
  sampleoutput:-acb
                bac
                bca
                cba
                cab*/

#include <stdio.h>
int my_strlen(char *str)
{
    int len = 0;
    while(str[len] != '\0')
    {
        len++;
    }
    return len;
}
void combination(char *ptr, int start, int end)
{
    if(start != end)
    {
        for(int i = start; i < end; i++)
        {
            char temp = ptr[start];
            ptr[start] = ptr[i];
            ptr[i] = temp;
            combination(ptr,start + 1,end);
            temp = ptr[start];
            ptr[start] = ptr[i];
            ptr[i] = temp;
        }
    }
    else
    {
        printf("%s\n", ptr);
    }
}
int main()
{
    char str[100];
    int res = 0;
    printf("Enter the string: ");
    if(scanf("%s", str) != 1)
    {
        printf("Enter the correct string...");
        return 0;
    }
    int n = my_strlen(str);
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(str[i] == str[j])
            {
                res = 1;
                break;
            }
        }
        if(res)
        {
            break;
        }
    }
    if(res == 0)
    {
        combination(str,0,n);
    }
    else
    {
        printf("Invalid input..");
        return 0;
    }
}