#include "invt.h"
/* update_db - Load hash table data from a previously saved .txt backup file */
int update_db(ht_arr *h_table)
{
     /* Only load if the hash table is currently empty */
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        if(h_table[i].head != NULL)
        {
            printf("ERROR : Hash table is not empty\n");
            return FAILURE;
        }
    }
    char filename[20];
    printf("Enter the file name : ");
    scanf("%s", filename);

    /* Only allow .txt filenames */
    if(strstr(filename, ".txt") == NULL)
    {
        printf("ERROR : file name is not valid\n");
        return FAILURE;
    }

    
    FILE *fp = fopen(filename, "r");
    if(!fp)
        return FAILURE;
    
    /* Verify the magic string at the top of the file */
    char magic_string[20];
    int len = strlen(MAGIC_STRING);
    fread(magic_string, 1, len, fp);
    magic_string[len] = '\0';

    if(strcmp(magic_string, MAGIC_STRING) != 0)
    {
        printf("ERROR : The Magic String is not matching\n");
        fclose(fp);
        return FAILURE;
    }

    /* Read and parse each line after the magic string
     * Line format: #<index>;<word>;<f_count>;<w_count>;<f_name>;...#
     */
    char line[256];
    while(fscanf(fp, "%255[^\n]", line) == 1)
    {
        fgetc(fp);/* consume the newline */

        /* Token 1: index (skip it, insert_word calculates index itself) */
        char *token = strtok(line, ";#\n");
        if(token == NULL)
            continue;

        /* Token 2: word */
        token = strtok(NULL, ";#\n");
        if(token == NULL) 
            continue;
        
        char word[30];
        strncpy(word, token, sizeof(word) - 1);
        word[sizeof(word) - 1] = '\0';
 

        /* Token 3: file count */
        token = strtok(NULL, ";#\n");
        if(token == NULL) 
            continue;

        int f_count = atoi(token);

        /* Tokens 4+: pairs of w_count and f_name, one pair per file */
         for(int j = 0; j < f_count; j++)
        {
            char *wcount_tok = strtok(NULL, ";#\n");/* word count */
            char *fname_tok  = strtok(NULL, ";#\n");/* file name */
            if(wcount_tok == NULL || fname_tok == NULL) 
                break;
 
            int w_count = atoi(wcount_tok);

            /* Re-insert the word w_count times to rebuild the count correctly */
            for(int k = 0; k < w_count; k++)
            {
                insert_word(h_table, word, fname_tok);
            }
        }
    }

    fclose(fp);
    return SUCCESS;

}