/*update the 2D array elements with just the next prime, if it is not prime.
sample Input:
2 3
4 5 6
7 8 9


Process:
- 4 → next prime = 5
- 5 → already prime
- 6 → next prime = 7
- 7 → already prime
- 8 → next prime = 11
- 9 → next prime = 11
sample Output:
5 5 7
7 11 11*/

#include <stdio.h>

// Function to check if a number is prime
int isPrime(int n) 
{
    if (n <= 1) return 0;       // not prime
    if (n == 2) return 1;       // prime
    
    if (n % 2 == 0) return 0;   // even numbers > 2 are not prime
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Function to get next prime (or same if already prime)
int nextPrime(int n) {
    if (isPrime(n)) return n;
    int candidate = n + 1;
    while (!isPrime(candidate)) 
    {
        candidate++;
    }
    return candidate;
}

int main() {
    int rows, cols;
    printf("Enter rows and cols: ");
    scanf("%d %d", &rows, &cols);

    int arr[rows][cols];
    printf("Enter elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // Update each element to next prime
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = nextPrime(arr[i][j]);
        }
    }

    // Print updated matrix
    printf("Updated matrix with next primes:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}