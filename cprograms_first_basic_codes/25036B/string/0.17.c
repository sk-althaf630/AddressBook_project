#include <stdio.h>

void reverse(char *str, int i, int l) {
    if(i >= l) {
        return;
    }
    char temp = str[i];
    str[i] = str[l];
    str[l] = temp;
    reverse(str, i+1, l-1);
}

int main() 
{
    char str[100];
    printf("Enter the string: ");
    scanf("%[^\n]", str);
    int len = 0;
    while(str[len] != '\0')
    {
        len++;
    }
    reverse(str, 0, len-1);
    printf("Reversed string: %s\n", str);
    return 0;
}
