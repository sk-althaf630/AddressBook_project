/*Wap for Find the multiplication of 2 matrices (where c1=r2).
sample intput :- 1 2 3  (*) 1 2 3 4
                 4 5 6      5 6 7 8
                            9 1 2 3
sample output :- 38 17 23 29
                 83 44 59 74 */
#include <stdio.h>
int main()
{
    int r1, c1, r2, c2;
start://this act like a loop.
    printf("Enter the number of 1st rows : ");
    scanf("%d", &r1);

    printf("Enter the number of 1st cols : ");
    scanf("%d", &c1);

    printf("Enter the number of 2nd rows : ");
    scanf("%d", &r2);

    printf("Enter the number of 2nd cols : ");
    scanf("%d", &c2);

    if(c1 != r2)
    {
        printf("Invalid input try agin\n");
        goto start;//jump back to input stage.
        return 1;
    }
    int r3 = r1;
    int c3 = c2;

    int arr[r1][c1];
    printf("Enter the elements of 1st matrix (%d X %d = %d) is : \n", r1, c1, r1*c1);
    for(int i = 0; i < r1; i++)
    {
        for(int j = 0; j < c1; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int prr[r2][c2];
    printf("Enter the elements of 2nd matrix (%d X %d = %d) is : \n", r2, c2, r2*c2);
    for(int i = 0; i < r2; i++)
    {
        for(int j = 0; j < c2; j++)
        {
            scanf("%d", &prr[i][j]);
        }
    }

    int result[r3][c3];
    for(int i = 0; i < r3; i++)
    {
        for(int j = 0; j < c3; j++)
        {
            result[i][j] = 0;
            for(int k = 0; k < c1; k++)
            {
                result[i][j] += arr[i][k] * prr[k][j];
            }
        }
    }

    printf("The  multiplication of 2 matrices is : \n");
    for(int i = 0; i < r3; i++)
    {
        for(int j = 0; j < c3; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}