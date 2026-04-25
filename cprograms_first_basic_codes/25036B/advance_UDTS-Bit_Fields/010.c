/*
d.i = 10
d.f = 220.50
d.i after storing float = (garbage value)
*/
#include <stdio.h>

union Data {
    int i;        // integer
    float f;      // float
    char str[20]; // string
};

int main() {
    union Data d;   // create a union variable

    d.i = 10;       // store integer
    printf("d.i = %d\n", d.i);

    d.f = 220.5;    // now store float
    printf("d.f = %.2f\n", d.f);

    // Notice: d.i is overwritten because union shares memory
    printf("d.i after storing float = %d\n", d.i);

    return 0;
}