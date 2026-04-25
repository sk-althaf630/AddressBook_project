#include<stdio.h>
void print(int *ptr[], int size, int size2);
int main()
{
    int a[3]={10,20,30};
    int b[3]={40,50,60};
    int c[3]={70,80,90};
    int *arr[3]={a,b,c};
    
    /*//1st 1D array
    printf(" (*arr+0)+0) --> %d\t *(arr[0]+0) --> %d\t arr[0][0] --> %d\n", *(*(arr+0)+0), *(arr[0]+0), arr[0][0]);
    printf(" (*arr+0)+1) --> %d\t *(arr[0]+1) --> %d\t arr[0][1] --> %d\n", *(*(arr+0)+1), *(arr[0]+1), arr[0][1]);
    printf(" (*arr+0)+2) --> %d\t *(arr[0]+2) --> %d\t arr[0][2] --> %d\n", *(*(arr+0)+2), *(arr[0]+2), arr[0][2]);

    printf("\n");
    //2nd 1D array
    printf(" (*arr+1)+0) --> %d\t *(arr[1]+0) --> %d\t arr[1][0] --> %d\n", *(*(arr+1)+0), *(arr[1]+0), arr[1][0]);
    printf(" (*arr+1)+1) --> %d\t *(arr[1]+1) --> %d\t arr[1][1] --> %d\n", *(*(arr+1)+1), *(arr[1]+1), arr[1][1]);
    printf(" (*arr+1)+2) --> %d\t *(arr[1]+2) --> %d\t arr[1][2] --> %d\n", *((arr+1)+2), *(arr[1]+2), arr[1][2]);

    printf("\n");
    //3rd 1D array
    printf(" (*arr+2)+0) --> %d\t *(arr[2]+0) --> %d\t arr[2][0] --> %d\n", *(*(arr+2)+0), *(arr[2]+0), arr[2][0]);
    printf(" (*arr+2)+1) --> %d\t *(arr[2]+1) --> %d\t arr[2][1] --> %d\n", *(*(arr+2)+1), *(arr[2]+1), arr[2][1]);
    printf(" (*arr+2)+2) --> %d\t *(arr[2]+2) --> %d\t arr[2][2] --> %d\n", *(*(arr+2)+2), *(arr[2]+2), arr[2][2]);*/
    print(arr,3,3);
}

//when u pass the 2D array we need to collect that in double pointer
//whenever we pass array of pointer in the function we should collect in double pointers(int **ptr, int *ptr[])
void print(int *ptr[], int size, int size2)
{
    for(int i = 0; i <size; i++)
    {
        for(int j = 0; j < size2; j++)
        {
            printf("%d\t", ptr[i][j]);
        }
        printf("\n");
    }
}
