#include <stdio.h>
int prime(int);

int main()
{
    int arr[6] = {4, 5, 7, 8, 12, 15};
    for(int i = 0;i < 6; i++)
    {
        //prime(arr[i]);
        
        if(prime(arr[i]) ==0)
        {
            arr[i]++;
        }
        printf("%d is prime\n", arr[i]);
    }
}

int prime(int num)
{
    for(int i = 2; i * i < num; i++)
    {
        if(num % i ==0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}