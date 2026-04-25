#include "sll.h"

int sl_insert_nth(Slist **head, data_t data, data_t n)
{
    if(n < 1)
    {
        return POSITION_NOT_FOUND;
    }

    
    if(n == 1)
    {
        Slist *new_node = malloc(sizeof(Slist));
        if(!new_node)
        {
            return FAILURE;
        }


        new_node->data = data;
        new_node->link = *head;
        *head = new_node;
        return SUCCESS;
    }
    
    if(*head == NULL)
    {
        return LIST_EMPTY;
    }
    
    Slist *temp = *head;
    int count = 1;

    while(temp != NULL)
    {
        if(count == n-1)
        {
            Slist *new_node = malloc(sizeof(Slist));
            if(!new_node)
            {
                return FAILURE;
            }

            new_node->data = data;
            new_node->link = temp->link;
            temp->link = new_node;
            return  SUCCESS;
        }
        
        temp = temp->link;
        count++;
    }

    return POSITION_NOT_FOUND;
}