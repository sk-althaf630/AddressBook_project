/*Count the number of set bits.*/

#include <stdio.h>

int main()
{
    int num;
    printf("Enter the number : ");
    scanf("%d", &num);

    int count = 0;
    for(int i = 0; i < 32; i++)
    {
        if(num & (1 << i))
        {
            count++;
        }
    }

    printf("Count of the set bits of %d is %d\n", num, count);
    return 0;
}

/*#include <stdio.h>

int main() {
    int num;
    printf("Enter the number : ");
    scanf("%d", &num);

    int count = __builtin_popcount(num); // GCC/Clang built-in

    printf("Count of the set bits is %d\n", count);
    return 0;
}*/

/*#include <stdio.h>

int main() {
    int num;
    printf("Enter the number : ");
    scanf("%d", &num);

    int count = 0;
    while(num) {
        num &= (num - 1); // clears the lowest set bit
        count++;
    }

    printf("Count of the set bits is %d\n", count);
    return 0;
}*/