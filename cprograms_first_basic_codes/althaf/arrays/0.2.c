/*Copy the even and odd elements into two separate arrays
    sample input:- 1 2 3 4 5
    sample output:-even:-2 4 
                   odd:-1 3 5*/

#include <stdio.h>
int main()
{
    int size;
    printf("Enter the size: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements: ");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    int even = 0;
    int odd = 0;

    int even_count[size];
    int odd_count[size];

    for(int i = 0; i < size; i++)
    {
        if(arr[i] % 2 ==0)
        {
            even_count[even] = arr[i];
            even++;
        }
        else
        {
            odd_count[odd] = arr[i];
            odd++;
        }
    }
    
    printf("Even ---> ");
    for(int i = 0; i < even; i++)
    {
        printf("%d ", even_count[i]);
    }
    printf("\n");

    printf("Odd ---> ");
    for(int i = 0; i < odd; i++)
    {
        printf("%d ", odd_count[i]);
    }
    printf("\n");
    return 0;
}
