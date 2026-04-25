/*find the even and odd form the array then display.
sample i/p:- 1 2 3 4 5
sample o/p:- even = 2 4
             odd = 1 3 5
*/

#include <stdio.h>
int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array: ");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int even_count = 0;
    int odd_count = 0;

    int even[size];
    int odd[size];

    for(int i = 0; i < size; i++)
    {
        if(arr[i] % 2 == 0)
        {
            even[even_count++] = arr[i];
        }
        else
        {
            odd[odd_count++] = arr[i];
        }
    }

    printf("Even = ");
    for(int i = 0; i < even_count; i++)
    {
        printf("%d ", even[i]);
    }
    printf("\n");

    printf("odd = ");
    for(int i = 0; i < odd_count; i++)
    {
        printf("%d ", odd[i]);
    }
return 0;
}