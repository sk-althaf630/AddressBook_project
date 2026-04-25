#include <stdio.h>
int main()
{
    int size, i, lar = 0;
    printf("enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("enter the elements of the array: ");
    for(i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    int odd = 0, even =0;
    int odd_count[size];
    int even_count[size];
    for(i = 0; i < size; i++)
    {
        if(arr[i] % 2)
        {
            odd_count[odd] = arr[i];
            odd++;
        }
        else
        {
            even_count[even] = arr[i];
            even++;
        }
    }
    printf("Odd: ");
    for(i = 0; i < odd; i++)
    {
        printf("%d ", odd_count[i]);
    }
    printf("\n");
    printf("even: ");

    for(i = 0; i < even; i++)
    {
        printf("%d ", even_count[i]);

    }
    printf("\n");

}