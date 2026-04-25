#include "apc.h"

void addition(node *tail1, node *tail2, node **headR, node **tailR)
{
    node *temp1 = tail1;
    node *temp2 = tail2;

    int digit1, digit2;
    int carray = 0;
    while(temp1 != NULL || temp2 != NULL)
    {

        //assign values
        if(temp1 != NULL)
            digit1 = temp1->data;
        else
            digit1 = 0;
        if(temp2 != NULL)
            digit2 = temp2->data;
        else
            digit2 = 0;

        //doing the operation.
        int sum = digit1 + digit2 + carray;

         /*
         * A single-digit position can produce at most 9+9+1 = 19, so the
         * carry is at most 1 and the stored digit is (sum % 10).
         */
        if(sum > 9)
        {
            carray = sum / 10;
            sum %= 10;
        }
        else
        {
            carray = 0;
        }
            

        /* Insert at front so the result list grows MSB-first */
        insert_first(headR, tailR, sum);

        if(temp1 != NULL)
            temp1 = temp1->prev;
        if(temp2 != NULL)
            temp2 = temp2->prev;
    }

    /*
     * If a carry remains after the last digit, it becomes the new
     * most-significant digit (e.g., 999 + 1 → carry produces the leading 1).
     */
    if (carray > 0)
        insert_first(headR, tailR, carray);

}