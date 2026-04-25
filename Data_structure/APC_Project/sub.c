#include "apc.h"

void subtraction(node *head1, node *head2, node *tail1, node *tail2, node **headR, node **tailR)
{

    
    int cmp = compare_list(head1, head2);
    
    if(cmp == SAME)
    {
        insert_first(headR, tailR, 0);
        return;
    }

     /*
     * If operand1 < operand2, swap so that (head1/tail1) always points to
     * the LARGER value.  This ensures digit1 >= digit2 (after borrow
     * adjustment) and we never store a negative digit.
     * The caller in main.c already tracks which operand was larger and
     * applies the correct sign to the output.
     */
    if(cmp == OPERAND2)
    {
        //swap tail so we always subtract smaller from larger
        node *tmp;
        tmp = head1; 
        head1 = head2; 
        head2 = tmp;

        tmp = tail1; 
        tail1 = tail2; 
        tail2 = tmp;
    }

    node *temp1 = tail1;
    node *temp2 = tail2;


    int digit1, digit2;
    int borrow_flag = 0;

    while (temp1 != NULL || temp2 != NULL)
    {
        // assign values
        if (temp1 != NULL)
            digit1 = temp1->data;
        else
            digit1 = 0;

        if (temp2 != NULL)
            digit2 = temp2->data;
        else
            digit2 = 0;

        /* Apply any borrow carried in from the previous (lower) position */
        digit1 = digit1 - borrow_flag;

        /*
         * If digit1 is still less than digit2 after applying the existing
         * borrow, we must borrow 10 from the next higher position.
         */
        if (digit1 < digit2)
        {
            digit1 = digit1 + 10;
            borrow_flag = 1;
        }
        else
        {
            borrow_flag = 0;
        }

        int result = digit1 - digit2;

        insert_first(headR, tailR, result);

        // move both pointers
        if (temp1 != NULL)
            temp1 = temp1->prev;

        if (temp2 != NULL)
            temp2 = temp2->prev;
    }

     /*
     * Remove any leading zeros produced by the subtraction
     * (e.g., 1000 - 999 produces [0,0,0,1] before reversal, which after
     * reversal and removal becomes [1]).
     */
    remove_pre_zeros(headR, tailR); 
 
}