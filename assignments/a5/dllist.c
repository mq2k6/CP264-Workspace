/*
* --------------------------------------------------
Project:
File:    dllist.c
Author:  Mustafa Qasim
Version: 2025-10-10
--------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include "dllist.h"

/*
 * Create and return a new double linked list node using malloc()
 * with passed data value and returns pointer to the new node.
 */
NODE *dll_node(char value)
{
    NODE *node = (NODE *)malloc(sizeof(node));
    node->data = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

/*
 * Insert a given node at the beginning the of a doubly linked list.
 * @param DLL *dllp -  reference to input DLL variable
 * @param NODE *np  -  reference of a NODE node to be inserted
 */
void dll_insert_start(DLL *dllp, NODE *np)
{

    if (dllp->length < 1)
    {
        dllp->start = np;
        dllp->end = np;
        np->prev = NULL;
        np->next = NULL;
    }
    else
    {
        dllp->start->prev = np;
        np->prev = NULL;
        np->next = dllp->start;
        dllp->start = np;
    }
    dllp->length += 1;
}

/*
 * Insert a node at the end of a doubly linked list.
 * @param DLL *dllp -  reference to input DLL variable
 * @param NODE *np  -  reference of a NODE node to be inserted
 */
void dll_insert_end(DLL *dllp, NODE *np)
{

    if (dllp->length < 1)
    {
        dllp->start = np;
        dllp->end = np;
        np->prev = NULL;
        np->next = NULL;
    }
    else
    {
        dllp->end->next = np;
        np->next = NULL;
        np->prev = dllp->end;
        dllp->end = np;
    }
    dllp->length += 1;
}

/*
 * This deletes the first node of a doubly linked list.
 * @param DLL *dllp -  reference to input DLL variable
 */
void dll_delete_start(DLL *dllp)
{
    NODE *start = dllp->start;
    if (dllp->length == 1)
    {
        dllp->start = NULL;
        dllp->end = NULL;
    }
    else
    {
        dllp->start = dllp->start->next;
        dllp->start->prev = NULL;
    }

    free(start);
    dllp->length -= 1;
}

/*
 * Delete the end node of a doubly linked list.
 * @param DLL *dllp -  reference to input DLL variable
 */
void dll_delete_end(DLL *dllp)
{
    NODE *end = dllp->end;
    if (dllp->length == 1)
    {
        dllp->end = NULL;
        dllp->start = NULL;
    }
    else
    {
        dllp->end = dllp->end->prev;
        dllp->end->next = NULL;
    }

    free(end);
    dllp->length -= 1;
}

/*
 * Clean and free the nodes of a doubly linked list and reset start and length.
 * @param DLL *dllp -  reference to input DLL variable
 */
void dll_clean(DLL *dllp)
{
    if (dllp->length > 0 && dllp->start)
    {
        NODE *curr = dllp->start;

        while (curr->next)
        {
            free(curr);
            curr = curr->next;
        }

        dllp->length = 0;
        dllp->end = NULL;
        dllp->start = NULL;
    }
}