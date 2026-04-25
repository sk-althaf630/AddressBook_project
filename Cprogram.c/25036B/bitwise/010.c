/*Make number -ve without using ‘-’ sign.
sample input :- 5 and  0
sample output:- -5  and 0*/
#include <stdio.h>

int main() {
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);

    int neg = (~num) + 1;  // two's complement
   // int neg = num * ((~1) + 1);  // multiply by -1
   //int neg = 0 - num;  // equivalent to -num

    printf("Negative of %d is %d\n", num, neg);

    return 0;
}