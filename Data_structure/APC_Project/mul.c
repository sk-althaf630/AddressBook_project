#include "apc.h"

void multiplication(node *tail1, node *tail2, node **headR1, node **tailR1)
{
    node *headR2 = NULL, *tailR2 = NULL;
    node *head_AR = NULL, *tail_AR = NULL;

    node *temp1 = tail1, *temp2 = tail2;
    int count = 0;
    int carray = 0;

    while(temp2 != NULL)
    {
        int num = temp2->data;
        temp1 = tail1;

        carray = 0;

        /*
         * ── Add the PREVIOUS partial product into the running total ──
         *
         * We can only do this starting from count==1 (second row) onward,
         * AND only when headR2 has already been built (it is NULL on the
         * very first pass through count==1 because we build headR2 during
         * that same iteration, not before it).
         *
         * Timeline:
         *   count=0: build headR1 directly; headR2 stays NULL → skip.
         *   count=1: headR2 is NULL at loop top (built below) → skip.
         *            At end of this iteration headR2 holds row-1 product.
         *   count=2: headR2 != NULL → add headR1 + headR2, store in headR1.
         *   count=N: same as count=2.
         * The final pending headR2 (from the last iteration) is merged
         * AFTER the loop by the second addition block.
         */
        if(count != 0 && headR2 != NULL)
        {
            addition(*tailR1, tailR2, &head_AR, &tail_AR);
            delete_list(headR1, tailR1);
            delete_list(&headR2, &tailR2);

            *headR1 = head_AR;
            *tailR1 = tail_AR;

            head_AR = NULL;
            tail_AR = NULL;
        }

        /*
         * ── Apply place-value shift: prepend `count` zeros ──
         * These zeros represent the positional shift (×10 per digit position).
         * They go into headR2 (or headR1 for the first row, but count==0 so
         * pad==0 and the loop body never runs for the first row).
         */
        int pad = count;
        while(pad != 0)
        {
            insert_first(&headR2, &tailR2, 0);
            pad--;
        }

        /*
         * ── Multiply every digit of operand1 by `num` ──
         * Walk operand1 from LSB to MSB (tail → head) and build the partial
         * product digit by digit, inserting at the front so the result is
         * in MSB-first order.
        */
        while(temp1 != NULL)
        {
            int result = carray + temp1->data * num;
            if(result > 9)
            {
                carray = result / 10;
                result %= 10;
            }
            else
            {
                carray = 0;
            }

        /* First row goes into the running-total list directly */
            if(count == 0)
                insert_first(headR1, tailR1, result);
            else
                insert_first(&headR2, &tailR2, result);

            temp1 = temp1->prev;
        }

        /* If a carry remains after the last digit, prepend it */
        if(carray > 0)
        {
            if(count == 0)
                insert_first(headR1, tailR1, carray);
            else
                insert_first(&headR2, &tailR2, carray);
                
            carray = 0;
        }
        count++;
        temp2 = temp2->prev;
    }
    /*
     * ── Merge the final partial product (headR2) into the running total ──
     *
     * After the loop, headR2 holds the last row's partial product which
     * was never added (see the "count==1" note above — the addition at the
     * top of the loop fires one iteration AFTER headR2 is built, so the
     * very last headR2 is always left pending).
     *
     * If operand2 had only ONE digit (count ended at 1), headR2 is NULL
     * and this block is skipped — headR1 already holds the full result.
     */
    if(*headR1 != NULL && headR2 != NULL)
    {
        addition(*tailR1, tailR2, &head_AR, &tail_AR);
        delete_list(headR1, tailR1);
        delete_list(&headR2, &tailR2);

        *headR1 = head_AR;
        *tailR1 = tail_AR;
    }

    /* Strip any leading zeros (e.g., 0 × anything = 0, not "00…0") */
    remove_pre_zeros(headR1, tailR1);
}
