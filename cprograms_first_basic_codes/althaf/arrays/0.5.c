/*find second largest using arrays
sample i/p:- 11 2 22 40
sample o/p:- 40,22 
*/

#include <stdio.h>
int main()
{
    int size;
    printf("Enter the size of an Array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elemnts of an Array: ");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    int first_lar = arr[0];
    int second_lar = 0;

    for(int i = 1; i < size; i++)
    {
        if(arr[i] > first_lar)
        {
            second_lar = first_lar;
            first_lar = arr[i];
        }
        else if(arr[i] > second_lar && arr[i] < first_lar)
        {
            second_lar = arr[i];
        }
    }
    printf("The first largest in array: %d\n", first_lar);
    printf("The second largest in array: %d\n", second_lar);
}