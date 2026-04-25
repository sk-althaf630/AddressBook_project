/*it is lly to remove duplicates
Print array without repetition.
sample input:- 1 2 3 4 5 5
sample output:- 1 2 3 4 5

*/

#include <stdio.h>

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

    printf("Array without repetition: ");
    for(int i = 0; i < size; i++)
    {
        int isRepeated = 0;

        // Check if arr[i] appeared before
        for(int j = 0; j < i; j++)
        {
            if(arr[i] == arr[j])
            {
                isRepeated = 1;
                break;
            }
        }

        // Print only if not repeated earlier
        if(!isRepeated)
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    return 0;
}