#include "sll.h"

int sl_delete_element(Slist **head, data_t data)
{
    if(*head == NULL)
    {
        return LIST_EMPTY;
    }

    Slist *temp = *head;
    Slist *prev = NULL;
    while(temp != NULL)
    {
        if(temp->data == data)
        {
            if(temp == *head)
            {
                *head = temp->link;
                free(temp);
                return SUCCESS;
            }
            else
            {
                prev->link = temp->link;
                free(temp);
                return SUCCESS;
            }

        }
        prev = temp;
        temp = temp->link;
    }

    return FAILURE;
}