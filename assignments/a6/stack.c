/*
* --------------------------------------------------
Project:
File:    stack.c
Author:  Mustafa Qasim
Version: 2025-10-27
--------------------------------------------------
*/

#include "stack.h"

/*
 * Push a node into a linked list stack
 * @param STACK *sp - pointer to the stack
 * @param NODE *np - pointer to the node.
 */
void push(STACK *sp, NODE *np)
{
    if (sp->length >= 1)
    {
        np->next = sp->top;
    }
    sp->top = np;
    sp->length += 1;
}

/*
 * Pop and return the pointer of the removed top node
 * @param STACK *sp - pointer to the stack
 * @return - the reference of the removed node and set it's next to NULL
 */
NODE *pop(STACK *sp)
{
    NODE *cp = sp->top;
    sp->top = sp->top->next;
    cp->next = NULL;
    sp->length -= 1;
    return cp;

}

/*
 * clean the linked list stack
 */
void clean_stack(STACK *sp)
{
    clean(&(sp->top));
    sp->top = NULL;
    sp->length = 0;
}