//6.Count the number of charactors in the file.
#include <stdio.h>
int main()
{
    FILE *fp;
    char ch;
    int char_count = 0;

    if((fp = fopen("char_count.txt" , "r")) == NULL)
    {
        perror("file is not found\n");
        return 1;
    }

    while((ch = fgetc(fp)) !=EOF)
    {
        int char_index = 0;
        if(ch == ' ' || ch == '\n' || ch == '\t')
        {
            char_index = 1;
        }
        else
        {
            if(char_index == 0)
            {
                char_count++;
                char_index = 1;
            }
        }
    }
    printf("The count of the charators in the file is %d\n", char_count);

    fclose(fp);
    return 0;
}