/*
Rotate array N times by right/left based on +ve/-ve entry from user.
Enter the size of the array : 5
Enter the elements of the array : 1 2 3 4 5
Enter rotation count (+ve for right, -ve for left): 2
Rotated array: 4 5 1 2 3


Enter rotation count (+ve for right, -ve for left): -2
Rotated array: 3 4 5 1 2
*/

#include <stdio.h>

int main()
{
    int size, N;
    printf("Enter the size of the array : ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array : ");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter rotation count (+ve for right, -ve for left): ");
    scanf("%d", &N);

    // Normalize N: handles both +ve/-ve and values larger than size
    N = ((N % size) + size) % size;
    // N =  7, size = 5 → ((7 % 5 =  2)+5 = 7) % 5 = 2
    // N = -2, size = 5 → -((2 % 5 = -2)+ 5 = 3)% 5 = 3
    // N = -7, size = 5 → ((-7 % 5 = -2) + 5 = 3) % 5 =3
    // N = -5, size = 5 → ((-5 % 5 =  0) + 5 = 5) % 5 = 0

    // Create rotated array
    int rotated[size];
    for(int i = 0; i < size; i++)
    {
        rotated[(i + N) % size] = arr[i];
    }

    // Print rotated array
    printf("Rotated array: ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", rotated[i]);
    }
    printf("\n");

    return 0;
}
// arr = [1, 2, 3, 4, 5],  size = 5,  N = 2
// ```

// | i | arr[i] | new pos = (i+2)%5 | rotated |
// |---|--------|-------------------|---------|
// | 0 | 1 | (0+2)%5 = **2** | rotated[2] = 1 |
// | 1 | 2 | (1+2)%5 = **3** | rotated[3] = 2 |
// | 2 | 3 | (2+2)%5 = **4** | rotated[4] = 3 |
// | 3 | 4 | (3+2)%5 = **0** | rotated[0] = 4 |
// | 4 | 5 | (4+2)%5 = **1** | rotated[1] = 5 |
// ```
// rotated = [4, 5, 1, 2, 3]  ✅