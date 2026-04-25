#include "invt.h"

// Validateing the commend line arguments
int validate_cla(int argc, char *argv[], flist **head_f_list)
{
    if(argc < 2)
    {
        return FAILURE;
    }

    for(int i = 1; i < argc; i++)
    {
        if(strstr(argv[i], ".txt") != NULL)
        {
			flist *temp = *head_f_list;
			int isduplicate = 0;

			while(temp != NULL)
			{
				if(strcmp(argv[i], temp->data) == 0)
				{
					isduplicate = 1;
					break;
				}
				temp = temp->link;
			}

			if(!isduplicate)
			{
				if(insert_first(argv[i], head_f_list) == FAILURE)
				{
					return FAILURE;
				}
			}
			else
			{
				fprintf(stderr, "Warning: skipping duplicate file: %s\n", argv[i]);
			}
        }
    }

	return SUCCESS;
}

/* istextpresent - Check if a file exists and is not empty
 * Returns FAILURE if file can't be opened or has 0 bytes */
int istextpresent(char *filename)
{
	FILE *fptr;
	if((fptr = fopen(filename, "r")) == NULL)
	{
		fprintf(stderr, "Could not open file: %s\n", filename);
		return FAILURE;
	}

	 /* Seek to end to get file size */
	fseek(fptr, 0, SEEK_END);
	long size = ftell(fptr);
	fclose(fptr);

	if(size == 0)
	{
	   fprintf(stderr, "File is empty: %s\n", filename);
	   return FAILURE;
	}
		
 return SUCCESS;

}

/* insert_first - Add a filename to the front of the file list
 * Checks the file is valid before inserting */
int insert_first(char *filename, flist **head_f_list)
{
	if(istextpresent(filename) == FAILURE)
	{
		return FAILURE;
	}

	flist *new_node = malloc(sizeof(flist));
	if(!new_node)
		return FAILURE;
	
	new_node->data = malloc(strlen(filename) + 1);
    if(!new_node->data)
    {
        free(new_node);
        return FAILURE;
    }
	strcpy(new_node->data, filename);
	new_node->link = NULL;
	if(*head_f_list == NULL)
	{
		*head_f_list = new_node;
		return SUCCESS;
	}
	else
	{
		new_node->link = *head_f_list;
		*head_f_list = new_node;
		return SUCCESS;
	}
}

/* print_list - Print all filenames in the list */
void print_list(flist **head_f_list)
{
	if(*head_f_list == NULL)
	{
		printf("ERROR : LIST IS EMPTY\n");
		return;
	}

	flist *temp = *head_f_list;
	printf("head ->");

	while(temp != NULL)
	{
		printf(" %s->", temp->data);
		temp = temp->link;
	}

	printf(" NULL\n");
}

/* insert_ht - Initialize the hash table
 * Sets all 28 buckets to index value with head = NULL */
void insert_ht(ht_arr *table)
{
	for(int i = 0; i < TABLE_SIZE; i++)
	{
		table[i].index = i;
		table[i].head = NULL;
	}

	printf("Hash_Table is successfully created\n");
}

/* validate_files - Remove already-indexed files from the file list
 * Used when update_db was loaded before create_db, to avoid re-indexing */
void validate_files(ht_arr *h_table, flist **head_f_list)
{
	for(int i = 0; i < TABLE_SIZE; i++)
	{
		if(h_table[i].head == NULL)
		{
			continue;
		}

		/* Walk every main-node and sub-node in this bucket */
		m_node *mtemp = h_table[i].head;
		while(mtemp != NULL)
		{
			s_node *stemp = mtemp->s_link;
			while(stemp != NULL)
			{
				/* If this filename is in the file list, remove it */
				flist *temp = *head_f_list;
				while(temp != NULL)
				{
					flist *next = temp->link;
					if(strcmp(stemp->f_name, temp->data) == 0)
					{
						delet_elemtent(head_f_list, stemp->f_name);
						break;
					}
					temp = next;
				}
				stemp = stemp->link;
			}
			mtemp = mtemp->m_link;
		}
	}
}

/* delet_elemtent - Delete a node with the given filename from the file list */
void delet_elemtent(flist **head_f_list, char *data)
{
	flist *temp = *head_f_list;
	flist *pre = NULL;

	while(temp != NULL)
	{
		if(strcmp(temp->data, data) == 0)
		{
			/* Unlink the node */
			if(temp == *head_f_list)
			{
				*head_f_list = temp->link;
			}
			else
			{
				pre->link = temp->link;
			}
			free(temp);
			return;
	    }
		pre = temp;
		temp = temp->link;
	}
}