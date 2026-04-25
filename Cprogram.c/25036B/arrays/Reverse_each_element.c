/*Reverse each element of the array at their index.
sample input:- 123, 456, 789, 101, 202
sample output:-After reverse_each_elements :
                Index 0: 321
                Index 1: 654
                Index 2: 987
                Index 3: 101
                Index 4: 202*/
#include <stdio.h>

// Function to reverse digits of a number
int reverse_each_elements(int num)
{
    int reverse = 0; // Initialize to 0
    while(num != 0)
    {
        int digit = num % 10;          // Extract last digit
        reverse = reverse * 10 + digit; // Append digit to reversed number
        num = num / 10;                 // Remove last digit
    }
    return reverse;
}

int main()
{
    int size;
    printf("Enter the size of an array : ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the array elements : \n");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Reverse each element
    for(int i = 0; i < size; i++)
    {
        arr[i] = reverse_each_elements(arr[i]);
    }

    // Print results
    printf("After reverse_each_elements : \n");
    for(int i = 0; i < size; i++)
    {
        printf("Index %d: %d\n", i, arr[i]);
    }

    return 0;
}