/*Print 2 power series.*/

#include <stdio.h>

int main() {
    int n;
    printf("Enter how many terms you want: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("2^%d = %d\n", i, 1 << i);
        // (1 << i) shifts 1 left by i bits → gives 2^i
    }

    return 0;
}

/*checking the given number is dividual are not
sample input :- num = 10, n = 5
sample out :- 10/5yes

#include <stdio.h>

int main() {
    int num, n;
    printf("Enter the number: ");
    scanf("%d", &num);

    printf("Enter the divisor (must be a power of 2): ");
    scanf("%d", &n);

    if((n & (n - 1)) != 0) {
        printf("%d is not a power of 2, bitwise check won't work directly.\n", n);
    } else {
        if((num & (n - 1)) == 0) {
            printf("%d is divisible by %d\n", num, n);
        } else {
            printf("%d is NOT divisible by %d\n", num, n);
        }
    }

    return 0;
}*/