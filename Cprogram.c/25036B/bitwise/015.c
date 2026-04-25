/*
Implement post inc/dec operator using bitwise (as a function).
Original num = 5
PostInc result = 5
After PostInc num = 6
PostDec result = 6
After PostDec num = 5*/

#include <stdio.h>

// Bitwise +1
int addOne(int x) {
    int m = 1;
    while (x & m) {
        x ^= m;
        m <<= 1;
    }
    x ^= m;
    return x;
}

// Bitwise -1
int subOne(int x) {
    int m = 1;
    while (!(x & m)) {
        x ^= m;
        m <<= 1;
    }
    x ^= m;
    return x;
}

// Post-increment (return old value, then increment)
int postInc(int *x) {
    int old = *x;
    *x = addOne(*x);
    return old;
}

// Post-decrement (return old value, then decrement)
int postDec(int *x) {
    int old = *x;
    *x = subOne(*x);
    return old;
}

int main() {
    int num = 5;

    printf("Original num = %d\n", num);
    printf("PostInc result = %d\n", postInc(&num));
    printf("After PostInc num = %d\n", num);

    printf("PostDec result = %d\n", postDec(&num));
    printf("After PostDec num = %d\n", num);

    return 0;
}