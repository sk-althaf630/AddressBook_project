/*rotate the 2D array by 90 degree (anticlockwise).
sample input :- 1 2 3
                4 5 6
                7 8 9
sample output:-  Transpose →
                        1 4 7
                        2 5 8
                        3 6 9
               - Reverse each row →
                        3 6 9
                        2 5 8
                        1 4 7*/

#include <stdio.h>

int main()
{
    int size;
    printf("Enter the size of the 2D-array : ");
    scanf("%d", &size);

    int arr[size][size];
    printf("Enter the elements of 2D-array : \n");
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    //step1 :- Transpose
    for(int i = 0; i < size; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    //step2 :- Reverse each column
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size/2; j++)
        {
            int temp = arr[j][i];
            arr[j][i] = arr[size - 1 - j][i];
            arr[size - 1 - j][i] = temp;
        }
    }

   // Print rotated matrix
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