#include "invt.h"
/* save_db - Write the entire hash table to a .txt backup file
 * Format of each line:  #<index>;<word>;<f_count>;<w_count>;<f_name>;...#
 */
int save_db(ht_arr *h_table)
{
    char filename[20];
    printf("Enter the backup file name : ");
    scanf("%s", filename);

    /* Only allow .txt filenames */
    if(strstr(filename, ".txt") == NULL)
    {
        printf("ERROR : file name is not valid\n");
        return FAILURE;
    }

    FILE *fp;
    fp = fopen(filename, "w");
    if(fp == NULL)
    {
        printf("file open is error\n");
        return FAILURE;
    }

    /* Write magic string at the top so update_db can verify the file */
    fprintf(fp, MAGIC_STRING);

	for(int i = 0; i < TABLE_SIZE; i++)
    {
        m_node *temp = h_table[i].head;
        h_table[i].head = NULL;/* Clear the bucket after saving */

        /* Write each word and its file list */
        while(temp != NULL)
        {
            fprintf(fp, "#%d;%s;%d;", i,temp->word, temp->f_count);
            /* Write each sub-node: word_count;filename; */
            s_node *temp1 = temp->s_link;
            
            while(temp1 != NULL)
            {
                fprintf(fp, "%d;%s;", temp1->w_count,temp1->f_name);
                temp1 = temp1->link;
            }
            fprintf(fp,"#\n");
        temp = temp->m_link;
        }
    }

    fclose(fp);
    return SUCCESS;
}