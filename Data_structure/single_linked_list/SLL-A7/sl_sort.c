#include "sll.h"

int sl_sort(Slist **head)
{
    if(*head == NULL)
    {
        return LIST_EMPTY;
    }

    Slist *first;
    Slist *second;
    Slist *prev;

    int count = 0;
    first = *head;
    while(first != NULL)
    {
        count++;
        first = first->link;
    }

    printf("the count %d", count);

    for(int i = 0; i < count-1; i++)
    {
        first = (*head)->link;
        second = *head;
        prev = NULL;

        for(int j = 0; j < count - i - 1; j++)
        {
            if(second->data > first->data)
            {
                second->link = first->link;
                first->link = second;

                if(prev == NULL)
                {
                    *head = first;

                }
                else
                {
                    prev->link = first;

                }
                prev = first;
                first = second->link;
            }
            else
            {
                prev = second;
                second = first;
                first = first->link;
            }
        }
    }
    return SUCCESS;
}