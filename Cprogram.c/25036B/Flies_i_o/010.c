//9.Print the nth line of the file.
#include <stdio.h>
int main()
{
    FILE *fp;
    int n;
    printf("Enter the number for which line U want to print : ");
    scanf("%d", &n);

    if((fp = fopen("which_line.txt" , "r")) ==NULL)
    {
        perror("file is not found\n");
        return 1;
    }

    int count = 0;
    char buffer[256];

    //loop will read every line of text in file until the count reaches to n
    while(fgets(buffer, sizeof(buffer), fp))
    {
        count++;
        if(count == n)
        {
            printf("%s\n", buffer);
            break;
        }
    }

    fclose(fp);
    return 0;
}