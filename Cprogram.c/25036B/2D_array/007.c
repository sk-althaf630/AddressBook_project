/*WAP for find the largest element of the whole 2D array.
sample input :- 1 3 2
                4 5 6
sample output :- largest = 6*/ 
#include <stdio.h>
int main()
{
    int rows, cols;

    // Step 1: Ask user for matrix size
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int arr[rows][cols]; //Declare 2D array

    //step 2: Ask user for matrix elements
    printf("Enter the elements of matrix : \n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    //step 3: finding the largest element from matrix
    int largest = arr[0][0];
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(arr[i][j] > largest)
            {
                largest = arr[i][j];
            }
        }
    }

    printf("The largest element of the whole 2D array is %d\n", largest);
    return 0;
}