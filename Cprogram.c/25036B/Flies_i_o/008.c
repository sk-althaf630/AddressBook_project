//7.Count the number of words in the file.
#include <stdio.h>
int main()
{
    FILE *fp;
    char ch;
    int word_count = 0;
    int word_index = 0;

    if((fp = fopen("word_count.txt" , "r")) == NULL)
    {
        perror("file is not found\n");
        return 1;
    }

    while((ch = fgetc(fp)) !=EOF)
    {
        if(ch == ' ' || ch == '\n' || ch == '\t')
        {
            word_index = 0;
        }
        else
        {
            if(word_index == 0)
            {
                word_count++;
                word_index = 1;
            }
        }
    }
    printf("The count of the words in the file is %d\n", word_count);
    
    fclose(fp);
    return 0;
}