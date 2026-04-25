/*
Name: Shaik.Althaf
Project: Arbitrary Precision Calculator
Submission Date: 09/04/2026
Submission Time: 7:30PM
Description:--
This project implements an Arbitrary Precision Calculator using the C programming
language. Unlike standard calculators limited by fixed data types, this system
supports computations on integers and floating-point numbers of virtually unlimited
size and precision. It provides functionality for addition, subtraction, multiplication,
division, and modular arithmetic, all achieved through manual parsing, dynamic memory
management, and linked list/buffer handling. The project demonstrates practical
applications of data structures, error handling, and low-level algorithm design,
making it valuable for understanding computational mathematics, cryptography, and
robust software engineering concepts.
*/

#include "apc.h"

int main(int argc, char *argv[])
{
    node *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;

    if (cla_validation(argc, argv) == FAILURE)
        return FAILURE;

    /* Determine sign of each operand (+1 or -1) */
    int sign1 = (argv[1][0] == '-') ? -1 : 1;
    int sign2 = (argv[3][0] == '-') ? -1 : 1;

    /* Skip the leading '+'/'-' sign character when building the digit list */
    char *num1 = (argv[1][0] == '+' || argv[1][0] == '-') ? argv[1] + 1 : argv[1];
    char *num2 = (argv[3][0] == '+' || argv[3][0] == '-') ? argv[3] + 1 : argv[3];

    create_list(num1, &head1, &tail1);
    create_list(num2, &head2, &tail2);

    char oper = argv[2][0];

    switch(oper)
    {
    case '+':
        if (sign1 == sign2)
        {
            // Same sign: add magnitudes, apply common sign
            addition(tail1, tail2, &headR, &tailR);
            if (sign1 == -1)
                printf("-");
            print_list(headR);
        }
        else
        {
            // Different signs: subtract smaller from larger, apply sign of larger
            int cmp = compare_list(head1, head2);
            if (cmp == OPERAND2 && sign2 == -1)
                printf("-");
            else if (cmp == OPERAND1 && sign1 == -1)
                printf("-");
            subtraction(head1, head2, tail1, tail2, &headR, &tailR);
            print_list(headR);
        }
        break;

    case '-':
        if (sign1 != sign2)
        {
            // Different signs: add magnitudes, apply sign of operand1
            addition(tail1, tail2, &headR, &tailR);
            if (sign1 == -1)
                printf("-");
            
            print_list(headR);
        }
        else
        {
            // Same sign: subtract, then determine sign
            int cmp = compare_list(head1, head2);

            subtraction(head1, head2, tail1, tail2, &headR, &tailR);
            if (sign1 == 1 && cmp == OPERAND2)
                printf("-");
            else if (sign1 == -1 && cmp == OPERAND1)
                printf("-");
            print_list(headR);
        }
        break;

    case 'x':
    case 'X':
        multiplication(tail1, tail2, &headR, &tailR);
        if (sign1 != sign2)
            printf("-");
        
        print_list(headR);
        break;

    case '/':
        /* Check divide-by-zero before printing sign */
        if((strcmp(num2,"0")) == 0)
        {
            printf("Error : You Cannot Divide By Zero\n");
            return FAILURE;
        }

        remove_pre_zeros(&head1, &tail1);
        remove_pre_zeros(&head2, &tail2);

        if(compare_list(head1,head2) == OPERAND2)
            insert_first(&headR, &tailR, 0);

        else if(compare_list(head1,head2) == SAME)
            insert_first(&headR, &tailR, 1);

        else
            division(head1, head2, tail2, &headR, &tailR);
        if (sign1 != sign2)
            printf("-");

			print_list(headR);
            break;

    default:
        printf("Invalid operator\n");
    }
    return SUCCESS;
}