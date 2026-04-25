#include "sll.h"

int sl_insert_before(Slist **head, data_t g_data, data_t ndata)
{
    if(*head == NULL)
    {
        return LIST_EMPTY;
    }

    Slist *temp = *head;
    Slist *prve = NULL;

    while(temp != NULL)
    {
        if(temp->data == g_data)
        {
            Slist *new_node = malloc(sizeof(Slist));
            if(!new_node)
            {
                return FAILURE;
            }

            new_node -> data = ndata;

            if(prve == NULL)
            {
                new_node->link = *head;
                *head = new_node;
                return SUCCESS;
            }
            else
            {
                new_node->link = temp;
                prve->link = new_node;

                return SUCCESS;
            }
        }

        prve = temp;
        temp = temp->link;
    }
    return DATA_NOT_FOUND;
}