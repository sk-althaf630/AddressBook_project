/*find first largest
sample i/p:- 11 2 22 40
sample o/p:- 40 
*/

#include <stdio.h>
int main()
{
    int size, i;
    printf("enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("enter the elements of the array: ");
    for(i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    int lar = arr[0];
    for(i = 1; i < size; i++)
    {
        if(arr[i] > lar)
        {
            lar = arr[i];
        }
    }
    printf("first large number in array: %d\n", lar);
    return 0;
}