/*find first largest using arrays
sample i/p:- 11 2 22 40
sample o/p:- 40 
*/

#include <stdio.h>
int main()
{
    int size;
    printf("Enter the size of a Array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of an Array: ");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    int lar = arr[0];
    for(int i = 1; i < size; i++)
    {
        if(arr[i] > lar)
        {
            lar = arr[i];
        }
    }
    printf("The first largest number of this Array is: %d\n", lar);
}