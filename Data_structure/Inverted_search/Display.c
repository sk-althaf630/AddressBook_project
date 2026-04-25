#include "invt.h"
/* display_table - Loop through all 28 buckets and print every entry */
void display_table(ht_arr *table) 
{
    printf("=====================================================================================================\n");
    printf("| Index |        Word      | Files_Count |      File Name       | Word_Count |\n");
    printf("=====================================================================================================\n");

    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        m_node *main = table[i].head;
        while (main) 
        {
            // Print the first line with index, word, and file count
            printf("| %-5d | %-16.16s | %-11d |", 
                   i, main->word, main->f_count);

            s_node *sub = main->s_link;
            if (sub == NULL) 
            {
                printf(" %-20s | %-10s |\n", "-", "-");
            } 
            else 
            {
                // First sub-node line
                printf(" %-20.20s | %-10d |\n", sub->f_name, sub->w_count);
                sub = sub->link;

                // Remaining sub-nodes: leave index/word/f_count columns blank
                while (sub) 
                {
                    printf("| %-5s | %-16s | %-11s | %-20.20s | %-10d |\n", 
                           " ", " ", " ", sub->f_name, sub->w_count);
                    sub = sub->link;
                }
            }

            printf("=====================================================================================================\n");
            main = main->m_link;
        }
    }
}