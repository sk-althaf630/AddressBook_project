/*it is the basic initialization
    sample input:- 
    sample output:-12 13 14
                   15 16 17*/

#include <stdio.h>
int main()
{
    int row = 2, colu = 3;
    int arr[2][3] = {{12, 13, 14} , {15, 16, 17}};

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < colu; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}