/*
* --------------------------------------------------
Project:
File:    myrecord_sllist.c
Author:  Mustafa Qasim
Version: 2025-10-09
--------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myrecord_sllist.h"

/**
 * Search singly linked list by the key name.
 *
 * @param SLL *sllp - provides the address of a singly linked list structure.
 * @param char *name - key to search
 * @return Pointer to found node if found; otherwise NULL
 */
NODE *sll_search(SLL *sllp, char *name)
{
    if (sllp->length == 0)
    {
        return NULL;
    }
    else
    {
        NODE *p = sllp->start;

        while (strcmp(p->data.name, name) != 0 && p->next != NULL)
        {
            p = p->next;
        }

        if (p->next == NULL && strcmp(p->data.name, name) != 0)
        {
            return NULL;
        }
        else
        {
            return p;
        }
    }
}

/**
 * Insert a new record to linked list at the position sorted by record name field.
 *
 * @param SLL *sllp - provides the address of a singly linked list structure.
 * @param char *name - name field of the new record.
 * @param float score - the score data of the new record.
 */
void sll_insert(SLL *sllp, char *name, float score)
{

    NODE *repl = (NODE *)malloc(sizeof(NODE));
    strcpy(repl->data.name, name);
    repl->data.score = score;

    if (sllp->length == 0)
    {
        repl->next = NULL;
        sllp->start = repl;
    }
    else
    {
        NODE *p = sllp->start;
        NODE *p1 = (NODE *)malloc(sizeof(NODE));
        while (strcmp(p->data.name, repl->data.name) < 0 && p->next != NULL)
        {
            p1 = p;
            p = p->next;
        }
        if (p == sllp->start)
        {
            repl->next = p;
            sllp->start = repl;
        }
        else
        {
            p1->next = repl;
            repl->next = p;
        }
    }

    sllp->length += 1;
}

/**
 * Delete a node of record matched by the name key from linked list.
 *
 * @param SLL *sllp provides the address of a singly linked list structure.
 * @param name - key used to find the node for deletion.
 * @return 1 if deleted a matched node, 0 otherwise.
 */
int sll_delete(SLL *sllp, char *name)
{

    if (sllp->length == 0 || sll_search(sllp, name) == NULL)
    {
        return 0;
    }

    if (sllp->length == 1)
    {
        sllp->start = NULL;
        sllp->length = 0;
    }
    else
    {
        NODE *p = sllp->start;
        NODE *p1 = (NODE *)malloc(sizeof(NODE));

        while (p != NULL && strcmp(p->data.name, name) != 0)
        {
            p1 = p;
            p = p->next;
        }

        if (p == sllp->start)
        {
            sllp->start = p->next;
        }
        else
        {
            p1->next = p->next;
        }
        free(p);
    }

    return 1;
}

/**
 * Clean singly linked list, delete all nodes.
 * @param @param SLL *sllp provides the address of a singly linked list structure.
 */
void sll_clean(SLL *sllp) {

    NODE *p = sllp->start;
    while (p != NULL) {
        NODE *tmp = p->next;
        free(p);
        p = tmp;
    }
    sllp->start = NULL;
    sllp->length = 0;
}