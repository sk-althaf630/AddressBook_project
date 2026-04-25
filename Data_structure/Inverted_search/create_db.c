#include "invt.h"

/* create_db - Open each file and insert all words into the hash table */
int create_db(ht_arr *ht_table, flist *head)
{
    flist *temp = head;
    char word[20];
    while(temp != NULL)
    { 
        FILE *fp = fopen(temp->data, "r");
        if(fp != NULL)
        {
            /* Read one word at a time and insert it */
            while(fscanf(fp, "%s", word) == 1)
            {
                if(insert_word(ht_table, word, temp->data) == FAILURE)
                {
                    return FAILURE;
                }
            } 
            fclose(fp); 
        }
        else
        {
            return FAILURE; /* File could not be opened */
        }
        temp = temp->link;
    }

    return SUCCESS;
}

/* index_find - Return the bucket index for a given character
 * a-z / A-Z  -> 0 to 25
 * digit      -> 26
 * other      -> 27
 */
int index_find(const char ch)
{
    if(ch >= 'a' && ch <= 'z')
    {
        return ch - 'a';
    }
    else if(ch >= 'A' && ch <= 'Z')
    {
        char lower = tolower(ch);
        return lower - 'a';
    }
    else if(isdigit(ch))
    {
        return 26;
    }
    else
    {
        return 27;
    }
}

/* insert_word - Insert a word + filename into the hash table
 * Case 1: word exists, file exists    -> increment word count
 * Case 2: word exists, file not found -> add new sub-node for that file
 * Case 3: word not found              -> add new main-node + sub-node
 */
int insert_word(ht_arr * ht_table, const char *word, const char *filename)
{
    int index = index_find(word[0]); /* Get the correct bucket */
    m_node *main = ht_table[index].head;

      /* Search for the word in the bucket */
    while(main != NULL){
        if(strcmp(word, main->word) == 0)
        {
             /* Word found — search for the filename in sub-nodes */ 
            s_node *sub = main->s_link;
           
          while(sub != NULL)
          {  
            if(strcmp(filename, sub->f_name) == 0)
            {
                sub->w_count++;/* File already tracked, just increment count */
                return SUCCESS;
            } 
            sub = sub->link;
          }

           /* File not found — add a new sub-node for this file */
          s_node *new_subnode = malloc(sizeof(s_node));
          if(!new_subnode)
          {
            printf("Sub-node Dynamical allocation is Failued\n");
            return FAILURE;
          }
          new_subnode->f_name = strdup(filename);
          new_subnode->w_count = 1;
          new_subnode ->link = main->s_link;/* Insert at front of sub-list */
          main->s_link = new_subnode;
          main->f_count++;
          return SUCCESS;
        }
       main = main->m_link;
    }

    /* Word not found — create a new main-node */
    m_node *new_Mnode = malloc(sizeof(m_node));
    if(!new_Mnode)
    {
        printf("main-node Dynamical allocation is Failued\n");
        return FAILURE;
    }
    
    new_Mnode->word = strdup(word);
    new_Mnode->f_count = 1;
    
     /* Create the first sub-node for this word */
    s_node *new_Snode = malloc(sizeof(s_node));
    if(!new_Snode)
    {
        printf("Sub-node Dynamical allocation is Failued\n");
        return FAILURE;
    }

    new_Snode->f_name = strdup(filename);
    new_Snode->w_count = 1;
    new_Snode->link = NULL;

     /* Link sub-node to main-node, then insert main-node at front of bucket */
    new_Mnode->s_link = new_Snode;
    new_Mnode->m_link = ht_table[index].head;
    ht_table[index].head = new_Mnode;

    return SUCCESS;
}