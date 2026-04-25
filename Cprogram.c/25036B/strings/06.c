// WAP to validate password string with one capital, small, digit, special and length be 8 at least.

// Enter password: Abc@1234
// Valid password.

// Enter password: abc123
// Invalid: Password must be at least 8 characters long.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;

    printf("Enter password: ");
    scanf("%[^\n]", password);   // read full line

    // check length
    if (strlen(password) < 8) {
        printf("Invalid: Password must be at least 8 characters long.\n");
        return 0;
    }

    // check each character
    for (int i = 0; password[i] != '\0'; i++) {
        if (isupper(password[i]))
            hasUpper = 1;
        else if (islower(password[i]))
            hasLower = 1;
        else if (isdigit(password[i]))
            hasDigit = 1;
        else
            hasSpecial = 1;
    }

    // final validation
    if (hasUpper && hasLower && hasDigit && hasSpecial)
        printf("Valid password.\n");
    else
        printf("Invalid password: must contain uppercase, lowercase, digit, and special character.\n");

    return 0;
}