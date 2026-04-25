/*
Convert array elements as 0/1 based on even/odd and find the decimal value of the array.
Enter the size of the array : 4
Enter the elements of the array : 2 5 8 7
Binary array (0/1 form): 0 1 0 1
Decimal value: 5
*/

#include <stdio.h>
int power(int i, int size)
{
    int res = 1;
    for(int j = 0; j < size; j++)
    {
        res *= 2;
    }

    return res;
}
int main()
{
    int size;
    printf("Enter the size of the array : ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array : ");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Step 1: Convert to 0/1 based on even/odd
    int bin[size];
    for(int i = 0; i < size; i++)
    {
        if(arr[i] % 2 == 0)
            bin[i] = 0;   // even → 0
        else
            bin[i] = 1;   // odd → 1
    }

    // Step 2: Calculate decimal value
    int decimal = 0;
    for(int i = 0; i < size; i++)
    {
        decimal += bin[i] * power(2, size - 1 - i);
    }

    // Print results
    printf("Binary array (0/1 form): ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", bin[i]);
    }
    printf("\nDecimal value: %d\n", decimal);

    return 0;
}