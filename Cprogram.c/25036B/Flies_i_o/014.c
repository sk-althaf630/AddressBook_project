//13.Delete the nth line from the given .txt file.
#include <stdio.h>
int main()
{
    FILE *fp, *temp;
    char buffer[256];
    int n, count = 0;

    if((fp = fopen("main_file.txt" , "r")) == NULL)
    {
        perror("file is not found\n");
        return 1;
    }

    if((temp = fopen("temp_file.txt" , "w")) == NULL)
    {
        perror("file is not found\n");
        fclose(fp);
        return 1;
    }
    
    printf("Enter line for delete : ");
    scanf("%d", &n);

    // Copy all lines except the nth one
    while((fgets(buffer, sizeof(buffer), fp)))
    {
        count++;
        if(count == n)
        {
            continue;//skip the nth line
        }
        fputs(buffer, temp);
    }

    fclose(fp);
    fclose(temp);

    // Replace original file with temp file
    remove("main_file.txt");
    rename("temp_file.txt", "main_file.txt");

    printf("Line %d deleted successfully.\n", n);
    return 0;
}