/*rotate the 2D array by 90 degree(clockwise).
sample input :- 1 2 3
                4 5 6
                7 8 9
sample output:-  Transpose →
                        1 4 7
                        2 5 8
                        3 6 9
               - Reverse each row →
                        7 4 1
                        8 5 2
                        9 6 3*/
#include <stdio.h>

int main()
{
    int size;
    printf("Enter the size of the 2D-array : ");
    scanf("%d", &size);

    int arr[size][size];
    printf("Enter the elements of the 2D-array : \n");
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    //step 1:- Transpose the array
    for(int i = 0; i < size; i++)
    {
        for(int j = 1 + i; j < size; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    printf("Matrix after Transpose : ");
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }


    //step 2:- reverse the array
    for(int i = 0; i< size; i++)
    {
        for(int j = 0; j < size/2; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[i][size-j-1];
            arr[i][size - j - 1] = temp;
        }
    }
    printf("Matrix after 90 degree anticlockwise rotation:\n");
        for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}