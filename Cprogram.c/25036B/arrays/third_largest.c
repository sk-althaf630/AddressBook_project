/*find first,second,third largest using arrays
sample i/p:- 11 2 22 40
sample o/p:- 40 
*/

#include <stdio.h>
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
    int first = arr[0];
    int second = 0;
    int third = 0;
    for(int i = 1; i < size; i++)
    {
        if(arr[i] > first)
        {
            third = second;
            second = first;
            first = arr[i];
        }
        else if(arr[i] > second)
        {
            third = second;
            second = arr[i];
        }
        else if(arr[i] > third)
        {
            third = arr[i];
        }
    }
    printf("The first largest number is: %d\n", first);
    printf("The second largest number is: %d\n", second);
    printf("The third largest number is: %d\n", third);

    return 0;
}