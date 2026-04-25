//WAP to implement atoi().
// Input: "   -567abc"
// - Skip spaces → " -567abc"
// - Detect '-' → sign = -1
// - Convert digits:
// - '5' → 5
// - '6' → 56
// - '7' → 567
// - Stop at 'a' (not a digit)
// - Apply sign → -567
// Output: -567

#include <stdio.h>

int myAtoi(const char *str) 
{
    int result = 0;      // final number
    int sign = 1;        // positive by default
    int i = 0;

    // Step 1: Skip leading whitespaces
    while (str[i] == ' ' || str[i] == '\t') 
    {
        i++;
    }

    // Step 2: Handle optional sign
    if (str[i] == '-') 
    {
        sign = -1;
        i++;
    } else if (str[i] == '+') 
    {
        i++;
    }

    // Step 3: Convert digits to integer
    while (str[i] >= '0' && str[i] <= '9') 
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return sign * result;
}

int main() 
{
    char str[100];
    printf("Enter a string number: ");
    scanf("%s", str);

    int num = myAtoi(str);
    printf("Converted integer: %d\n", num);

    return 0;
}