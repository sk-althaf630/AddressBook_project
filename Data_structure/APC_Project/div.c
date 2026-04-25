#include "apc.h"

void division(node *head_L1, node *head_opr2, node *tail_opr2, node **headR, node **tailR)
{
    node *head_opr1 = NULL;
    node *tail_opr1 = NULL;
    node *L1_temp = head_L1;
    node *head_sr = NULL;
    node *tail_sr = NULL;

    int sub_count = 0;
    insert_last(&head_opr1, &tail_opr1, L1_temp->data);

    // bring down digits until opr1 >= opr2
    while (compare_list(head_opr1,head_opr2) == OPERAND2)
    {
        L1_temp = L1_temp->next;
        insert_last(&head_opr1, &tail_opr1, L1_temp->data);
    }

    while(L1_temp != NULL)
    {
        // subtract opr2 from opr1 until opr1 < opr2
        while(compare_list(head_opr1,head_opr2) == OPERAND1 || compare_list(head_opr1,head_opr2) == SAME)
        {
            subtraction(head_opr1,  head_opr2, tail_opr1, tail_opr2, &head_sr, &tail_sr);
            delete_list(&head_opr1, &tail_opr1);
            head_opr1 = head_sr;
            tail_opr1 = tail_sr;

            head_sr = NULL;
            tail_sr = NULL;
            sub_count++;
        }
        insert_last(headR, tailR, sub_count);
        sub_count = 0;

        L1_temp = L1_temp->next;
        if(L1_temp != NULL)
        {
            insert_last(&head_opr1, &tail_opr1, L1_temp->data);
        }
        remove_pre_zeros(&head_opr1, &tail_opr1);
    }

    // Append the last quotient digit after loop ends
    if(sub_count != 0)
        insert_last(headR, tailR, sub_count);
    remove_pre_zeros(headR, tailR);
}
