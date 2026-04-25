// first dynamic second static (fdss)
#include <stdio.h>
#include <stdlib.h>

void scan(int (*ptr)[3], int row);
void print(int (*ptr)[3], int row);
void newscan(int (*ptr)[3], int row, int newrow);

int main()
{
    int row, newrow;

    printf("enter the no of rows: ");
    scanf("%d", &row);

    // dynamic rows
    int (*arr)[3] = malloc(row * sizeof(*arr));

    scan(arr, row);
    print(arr, row);

    printf("Enter the new no of rows: ");
    scanf("%d", &newrow);

    arr = realloc(arr, newrow * sizeof(*arr));

    if (newrow > row)
        newscan(arr, row, newrow);

    print(arr, newrow);

    free(arr);
    return 0;
}

void scan(int (*ptr)[3], int row)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            scanf("%d", &ptr[i][j]);
        }
    }
}

void print(int (*ptr)[3], int row)
{
    printf("the elements are:\n");
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d\t", ptr[i][j]);
        }
        printf("\n");
    }
}

void newscan(int (*ptr)[3], int row, int newrow)
{
    printf("Enter new elements:\n");
    for(int i = row; i < newrow; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            scanf("%d", &ptr[i][j]);
        }
    }
}