/*check the number is prisent in the array are not
    sample input:- 1 2 3 4 5
    sample output:-num 4 yesit prisent*/

#include <stdio.h>
int main()
{
    int size;
    printf("Enter the size of Array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of Array: ");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int num;
    printf("Enter the number to find in Array: ");
    scanf("%d", &num);

    int flage = 0;
    for(int i = 0; i < size;i++)
    {
        if(num == arr[i])
        {
            flage = 1;
            break;
        }
    }

    if(flage == 1)
    {
        printf("%d is prisent in array\n", num);
    }
    else
    {
        printf("%d is not prisent in array\n", num);
    }
}
