
#include "sll.h"

int sl_insert_after(Slist **head, data_t g_data, data_t ndata)
{
    if(*head == NULL)
    {
        return LIST_EMPTY;
    }
    
    Slist *temp = *head;
    
    while(temp != NULL)
    {
        if(temp->data != g_data)
        {
            
            temp = temp->link;
        }
        else
        {
            Slist *new_node = malloc(sizeof(Slist));
            if(!new_node)
            {
                return FAILURE;
            }
            
            new_node->data = ndata;
            new_node->link = temp->link;
            temp->link = new_node;
            
            return SUCCESS;
        }
    }
    
    return DATA_NOT_FOUND;
}
