/*set/get/clear/toggle a bit at a particular index position of a given number.
sample input:- num = a, n = 1
sample output:- After seting bit in 1 position = a
                After geting bit in 1 position = 1
                After clearing bit in 1 position = 8
                After toggleing bit in 1 position = 8*/

#include <stdio.h>

int main()
{
    int num;
    printf("Enter the hexdacimal number : ");
    scanf("%x", &num);

    int n;
    printf("Enter the position : ");
    scanf("%d", &n);

    int mask_set = num | (1 << n);
    int mask_get = (num >> n) & 1;
    int mask_clear = num & (~(1 << n));
    int mask_toggle = num ^ (1 << n);

    printf("After seting bit in %d position : %x\n", n, mask_set);
    printf("After geting bit in %d position : %x\n", n, mask_get);
    printf("After clearing bit in %d position : %x\n", n, mask_clear);
    printf("After toggleing bit in %d position : %x\n", n, mask_toggle);

    return 0;
}