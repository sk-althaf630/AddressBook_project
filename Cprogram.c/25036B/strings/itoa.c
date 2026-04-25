//WAP to implement itoa().
// Input: 1234
// Output: "1234"

// Input: -567
// Output: "-567"

// Input: 0
// Output: "0"

#include <stdio.h>
#include <string.h>

// Function to implement itoa()
void myItoa(int num, char *str) 
{
    int i = 0;
    int isNegative = 0;

    // Step 1: Handle 0 explicitly
    if (num == 0) 
    {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    // Step 2: Handle negative numbers
    if (num < 0) 
    {
        isNegative = 1;
        num = -num;
    }

    // Step 3: Extract digits
    while (num > 0) {
        int digit = num % 10;
        str[i++] = digit + '0';  // convert int → char
        num /= 10;
    }

    // Step 4: Add '-' if negative
    if (isNegative) {
        str[i++] = '-';
    }

    str[i] = '\0';

    // Step 5: Reverse the string
    int start = 0, end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() 
{
    int num;
    char str[100];

    printf("Enter an integer: ");
    scanf("%d", &num);

    myItoa(num, str);
    printf("Converted string: %s\n", str);

    return 0;
}