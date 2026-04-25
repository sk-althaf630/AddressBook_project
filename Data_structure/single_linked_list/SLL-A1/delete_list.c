#include "sll.h"

int sl_delete_list(Slist **head)
{
	if(*head == NULL)
	{
	    return FAILURE;
	}
	
	Slist *temp1 = *head;
	
	while(temp != NULL)
	{
    	Slist *temp2 = temp1->link;
	    free(temp1);
	    temp1 = temp2;
	}
	
	*head = NULL;
	
	return SUCCESS;
}