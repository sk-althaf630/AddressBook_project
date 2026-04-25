#include "sll.h"

int sl_delete_last(Slist **head)
{

    if (*head == NULL)
        return FAILURE;

    if ((*head)->link == NULL)
    {
        free(*head);
        *head = NULL;
        return SUCCESS;
    }

    Slist *temp = *head;
    Slist *prev = NULL;

    while (temp->link != NULL)
    {
        prev = temp;
        temp = temp->link;
    }

    prev->link = NULL;
    free(temp);

    return SUCCESS;
}