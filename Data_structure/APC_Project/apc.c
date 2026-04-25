#include "apc.h"

/*
* cla_validation() — validates command-line arguments.
*
* Expected format:  ./apc  <number1>  <operator>  <number2>
* argc must be 4 (program name + 3 arguments).
* Numbers may have an optional leading '+' or '-' sign.
* All remaining characters must be decimal digits.
*
* BUG FIX: the original code allowed a bare "+" or "-" with no digits
* (e.g., argv[1] = "-") to pass validation, because the digit loop started
* at index 1 and immediately saw '\0', so it never ran.  A bare sign would
* then create an empty list (create_list on "") causing undefined behaviour.
* The fix checks that at least one digit follows the optional sign.
*
* Returns SUCCESS (1) if valid, FAILURE (0) otherwise.
*/
int cla_validation(int argc, char *argv[])
{
    if(argc != 4)
    {
        printf("INVALID INPUT\n");
        return FAILURE;
    }
    int i = (argv[1][0] == '-' || argv[1][0] == '+') ? 1 : 0;
    
    for(; argv[1][i] != '\0'; i++)
    {
        if(!isdigit((unsigned char) argv[1][i]))
        {
            printf("PLS ENTER DIGITS ONLY\n");
            return FAILURE;
        }
    }

    int j = (argv[3][0] == '-'|| argv[3][0] == '+') ? 1 : 0;
    for(; argv[3][j] != '\0'; j++)
    {
        if(!isdigit((unsigned char) argv[3][j]))
        {
            printf("PLS ENTER DIGITS ONLY\n");
            return FAILURE;
        }
    }
    return SUCCESS;
}

/*
* create_list() — converts a digit string into a doubly-linked list.
*
* Each character in `opr` is expected to be a decimal digit ('0'–'9').
* The character's numeric value (ch - '0') is stored in each node.
* The head of the list holds the most-significant digit; the tail holds
* the least-significant digit.
*
* The caller must pass a sign-stripped string (no leading '+'/'-').
*/
void create_list(char *opr, node **head, node **tail)
{
    for(int i = 0;opr[i] != '\0';i++)
    {
        if(!(insert_last( head, tail,opr[i]-'0')))
        {
        printf("Operation Failed\n");
        return ;
        }
    }
}

/*
* insert_last() — appends a new node with `data` at the tail of the list.
*
* Returns SUCCESS on allocation success, FAILURE if malloc fails.
*/
int insert_last(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node));
  
  if(new == NULL)
  {
      return FAILURE;
  }
  
  new -> prev = NULL;
  new -> data = data;
  new -> next = NULL;
  
  if(*head == NULL)
  {
      *head=new;
      *tail=new;
      return SUCCESS;
  }
  
  (*tail)->next = new;
  new -> prev = *tail;
  *tail = new;
  return SUCCESS;
}

void print_list(node *head)
{
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    while (head)		
	    {
		    /* Printing the list */
		    printf("%d", head -> data);

		    /* Travering in forward direction */
		    head = head -> next;
	    }
    	printf("\n");
    }
}

int list_len(node *head)
{
    int count = 0;
    node *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

/*
* compare_list() — compares two non-negative numbers by magnitude.
*
* Returns:
*   OPERAND1  if list1 > list2
*   OPERAND2  if list2 > list1
*   SAME      if the values are equal
*
* Strategy:
*   1. The longer list (more digits) represents the larger number.
*   2. If lengths are equal, compare digit by digit from MSB to LSB;
*      the first differing digit determines the result.
*/
int compare_list(node *head1, node *head2)
{
    int list1_len = list_len(head1);
    int list2_len = list_len(head2);

    if (list1_len > list2_len)
        return OPERAND1;
    else if (list1_len < list2_len)
        return OPERAND2;
    else 
    {
        node *temp1 = head1;
        node *temp2 = head2;

        while (temp1 != NULL && temp2 != NULL) 
        {
            if (temp1->data > temp2->data)
                return OPERAND1;
            else if (temp1->data < temp2->data)
                return OPERAND2;
            else 
            {
                // move both pointers to the next node
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
    }
    return SAME;
}

/*
* insert_first() — prepends a new node with `data` at the head of the list.
*
* Used by addition(), subtraction(), and division() which build results
* from LSB to MSB and need to prepend each new digit.
*
* Returns SUCCESS on allocation success, FAILURE if malloc fails.
*/
int insert_first(node **head, node **tail, int data)
{
    node *new_node = malloc(sizeof(node));
    if(!new_node)
    {
        return FAILURE;
    }
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    if(*head == NULL)
    {
        *head = new_node;
        *tail = new_node;
    }
    else
    {
        new_node->next = *head;
        (*head)->prev = new_node;
        *head = new_node;
    }

    return SUCCESS;
}

/*
* delete_list() — frees every node in the list and resets head/tail to NULL.
*
* Returns FAILURE if the list is already empty, SUCCESS otherwise.
*/
int delete_list(node **head, node **tail)
{
    if(*head == NULL)
    {
        return FAILURE;
    }
    node *temp;
    while(*head != NULL)
    {
       temp = *head;
       *head = temp->next;
       free(temp);
    }
    
    *head = NULL;
    *tail = NULL;
    return SUCCESS;
}

/*
 * remove_pre_zeros() — removes leading zero nodes from the list.
 *
 * Example: [0, 0, 4, 2] → [4, 2]
 *
 * The last node is never removed even if it is zero, so "0" (a single zero
 * node) is preserved correctly.
 *
 * This is called after subtraction and division to clean up results like
 * "007" → "7", and after multiplication to handle 0 × N = 0.
 */
void remove_pre_zeros(node **head, node **tail)
{
    /* Stop when head==tail (preserve the single remaining node)
    or when the leading digit is non-zero */
    while (*head != NULL && (*head)->data == 0 && *head != *tail)
    {
        node *temp = *head;
        *head = (*head)->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
    }
}
