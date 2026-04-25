//first static second dynamic(fssd).
#include<stdio.h>
#include<stdlib.h>

void scan(int *ptr[], int row, int col);
void print(int *ptr[], int row, int col);
void newscan(int *ptr[], int row, int col, int newcol);
void newprint(int *ptr[], int row, int newcol);

int main()
{
    int row, col, newcol;

    printf("enter the no of rows & cols: ");
    scanf("%d %d", &row, &col);

    int *arr[row];

    for(int i = 0; i < row; i++)
        arr[i] = malloc(col * sizeof(int));

    scan(arr, row, col);
    print(arr, row, col);

    printf("Enter the new no of columns: ");
    scanf("%d", &newcol);

    for(int i = 0; i < row; i++)
        arr[i] = realloc(arr[i], newcol * sizeof(int));

    newscan(arr, row, col, newcol);
    newprint(arr, row, newcol);
    for(int i = 0; i < row; i++)
    {
        free(arr[i]);
    }

    return 0;
}


void scan(int *ptr[], int row, int col)
{

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            scanf("%d", &ptr[i][j]);
        }
    }
}

void print(int *ptr[], int row, int col)
{
    printf("the elements are:\n");
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("%d\t", ptr[i][j]);
        }
        printf("\n");
    }
}

void newscan(int *ptr[], int row, int col, int newcol)
{
    printf("Enter new elements:\n");
    for(int i = 0; i < row; i++)
    {
        for(int j = col; j < newcol; j++)
        {
            scanf("%d", &ptr[i][j]);
        }
    }
}

void newprint(int *ptr[], int row, int newcol)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < newcol; j++)
        {
            printf("%d\t", ptr[i][j]);
        }
        printf("\n");
    }
}