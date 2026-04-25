// WAP to validate the IP address of ipv4 with its property.
// Syntax : xxx.xxx.xxx.xxx , where each part is 0 - 255 (number only).

// Enter IPv4 address: 192.168.0.1
// Valid IPv4 address

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int isValidIPv4(char *ip) {
    int dots = 0;
    char *token;

    // split by "."
    token = strtok(ip, ".");
    while (token) {
        // check if token is numeric
        for (int i = 0; token[i]; i++) {
            if (!isdigit(token[i])) return 0;
        }

        // convert to integer
        int num = atoi(token);
        if (num < 0 || num > 255) return 0;

        dots++;
        token = strtok(NULL, ".");
    }

    // must have exactly 4 parts
    return (dots == 4);
}

int main() {
    char ip[50];
    printf("Enter IPv4 address: ");
    scanf("%s", ip);

    // make a copy since strtok modifies string
    char ipCopy[50];
    strcpy(ipCopy, ip);

    if (isValidIPv4(ipCopy))
        printf("Valid IPv4 address\n");
    else
        printf("Invalid IPv4 address\n");

    return 0;
}