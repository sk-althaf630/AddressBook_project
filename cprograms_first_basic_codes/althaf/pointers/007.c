/*WAP to check whether the number is prime are not in array and pointers
    sample input:- 1 2 3 4 5
    sample output:-y n y n y*/

#include <stdio.h>
void is_prime(int *ptr, int size);

int main()
{
    int size;
    printf("Enter the size of an array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of an array: ");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    is_prime(arr,size);
}

void is_prime(int *ptr, int size)
{
    for(int i = 0; i < size; i++)
    {
        int num = ptr[i];
        ptr[i] = ptr[i] % 2;
        if(ptr[i] == 0)
        {
            printf("%d is not a prime number\n", num);
        }
        else
        {
            printf("%d is a prime number\n", num);
        }
    }
}