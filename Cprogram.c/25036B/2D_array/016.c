/*WAP to swap both diagonal elements. [sq type] 
sample input :- 1  2  3
                4  5  6
                7  8  9
sample output:- Swap steps:
                Row 0: arr[0][0] ↔ arr[0][2] → 1 ↔ 3
                Row 1: arr[1][1] ↔ arr[1][1] → 5 ↔ 5 (no change)
                Row 2: arr[2][2] ↔ arr[2][0] → 9 ↔ 7

                After:
                3 2 1
                4 5 6
                9 8 7*/

#include <stdio.h>
int main()
{
    int n;
    printf("Enter the size of square matrix : ");
    scanf("%d", &n);

    int arr[n][n];
    printf("Enter the elements of square matrix : \n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Before swapping : \n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }


    //swaping the elements.
    for(int i = 0; i < n; i++)
    {
        int temp = arr[i][i];
        arr[i][i] = arr[i][n - i - 1];
        arr[i][n - i - 1] = temp;
    }

    printf("After swapping : \n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}