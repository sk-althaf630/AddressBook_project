/*check the number is prisent and count how many times it gon prisent in the array.
    sample input:- 5 7 8 6 5 7 9 6
    sample output:-5 ---> 2times
                   7 ---->2times
                   8 ----->1time
                   6 ----->2times*/
                   
#include <stdio.h>
int main()
{
    int size;
    printf("Enter the size of Array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of Array: ");
    for(int i = 0; i <size; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < size; i++)
    {
        int flag = 1;
        for(int j = 0; j < i; j++)
        {
            if(arr[j] == arr[i])
            {
                flag = 0;
                break;
            }
        }
        if(flag == 0)
        {
            continue;
        }
        int count = 1;
        for(int k = i + 1; k < size; k++)
        {
            if(arr[k] == arr[i])
            {
                count++;
            }
        }
        printf("%d ---> %dtimes\n", arr[i], count);
    }
}