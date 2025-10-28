/*
* --------------------------------------------------
Project:
File:    infix.c
Author:  Mustafa Qasim
Version: 2025-10-27
--------------------------------------------------
*/

#include "expression.h"
#include "stack.h"
#include <stdio.h>

/*
 * Convert infix expression string to postfix expression reprsented by queue data structure.
 * @param infixstr - string of infix expression.
 * @return - postfix expression in queue of QUEUE type.
 */
QUEUE infix_to_postfix(char *infixstr)
{
    char *p = infixstr;
    STACK opt = {0};
    QUEUE opd = {0};
    int pqp = 0;
    while (p[pqp])
    {
        int i = mytype(p[pqp]);
        int k = 1;

        if (i == 3) //start in brackets
        {
            while (opt.length > 0 && opt.top->data != '(')
            {
                enqueue(&opd, pop(&opt));
            }
            pop(&opt);
        }
        else if (i == 0) // operand
        {
            int data = p[pqp] - '0';
            while (mytype(p[pqp + k]) == 0) //horner's for str2int
            {
                data = data * 10 + p[pqp + k] - '0';
                k++;
            }
            enqueue(&opd, new_node(data, i));

            if (opt.top != NULL && priority(opt.top->data) == 1)
            {
                enqueue(&opd, pop(&opt));
            }
        }
        else if (p[pqp] == '-' && (pqp == 0 || (mytype(p[pqp - 1]) == 1 || mytype(p[pqp - 1]) == 2))) //negative operand
        {
            int data = p[pqp + 1] - '0';
            k = 2;
            while (mytype(p[pqp + k]) == 0) 
            {
                data = data * 10 + (p[pqp + k] - '0');
                k++;
            }
            data = -data;
            enqueue(&opd, new_node(data, 0));
            if (opt.top != NULL && priority(opt.top->data) == 1)
            {
                enqueue(&opd, pop(&opt));
            }
        }
        else if (i == 1 || i == 2) // operator or end of bracket
        {
            push(&opt, new_node(p[pqp], i));
        }
        pqp += k;
    }
    while (opt.length > 0)
    {
        enqueue(&opd, pop(&opt));
    }
    return opd;
}

/*
 * Evaluate and return the value postfix expression passed by queue.
 * @parame queue - postfix expression in queue of QUEUE type.
 ^ @return - value of postfix expression
*/
int evaluate_postfix(QUEUE queue)
{
    STACK s = {0};

    while (queue.length > 0)
    {
        NODE *x = dequeue(&queue);

        if (x->type == 0) // operand stored
        {
            push(&s, x);
        }
        else if (x->type == 1) // operate on top 2 items in stack
        {
            int sum = 0;
            int second = s.top->data;
            int first = s.top->next->data;

            switch (x->data)
            {
            case '+':
                sum = first + second;
                break;
            case '-':
                sum = first - second;
                break;
            case '*':
                sum = first * second;
                break;
            case '/':
                sum = first / second;
                break;
            case '%':
                sum = first % second;
                break;
            }
            pop(&s);
            pop(&s);
            push(&s, new_node(sum, 0));
        }
    }

    return (pop(&s)->data);
}

/*
 * Evaluate and return the value of infix expression passed by string infixstr,
 * using infix_to_postfix() and evaluate_postfix() functions.
 * @param infixstr - string of infix expression.
 * @return - value of the infix expression.
 */
int evaluate_infix(char *infixstr)
{
    return evaluate_postfix(infix_to_postfix(infixstr));
}