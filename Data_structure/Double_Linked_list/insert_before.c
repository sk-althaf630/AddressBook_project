#include "dll.h"

int dl_insert_before(Dlist **head, Dlist **tail, int gdata, int ndata)
{
    if(*head == NULL)
    {
        return LIST_EMPTY;
    }

    Dlist *temp = *head;
    while(temp != NULL)
    {
        if(temp->data == gdata)
        {
            Dlist *new_node = malloc(sizeof(Dlist));
            if(!new_node)
            {
                return FAILURE;
            }

            new_node->data = ndata;
            new_node->prev = temp->prev;
            new_node->next = temp;
            if(temp->prev != NULL)
            {
                temp->prev->next = new_node;
            }
            else
            {
                *head = new_node;
            }

            temp->prev = new_node;
            return SUCCESS;
        }
        temp = temp->next;
    }

    return DATA_NOT_FOUND;
}