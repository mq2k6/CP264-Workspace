/*
* --------------------------------------------------
Project:
File:    queue.c
Author:  Mustafa Qasim
Version: 2025-10-27
--------------------------------------------------
*/

#include "queue.h"

/*
 * Enqueue a node into a queue
 * @param *qp - pointer to the queue
 * @param NODE *np - pointer to the node.
 */
void enqueue(QUEUE *qp, NODE *np)
{
    if (qp->length == 0)
    {
        qp->front = np;
        qp->rear = np;
    }
    else
    {
        qp->rear->next = np;
        qp->rear = qp->rear->next;
    }
    np->next = NULL;
    qp->length += 1;
}

/*
 * Dequeue and return the pointer of the removed node.
 * @param *qp - pointer to the queue
 * @return - the reference of the removed node, and set it's next to NULL
 */
NODE *dequeue(QUEUE *qp)
{
    if (qp->length > 1)
    {
        NODE *rp = qp->front;
        qp->front = qp->front->next;
        qp->length -= 1;
        return rp;
    }
    else if (qp->length == 1)
    {
        NODE *rp = qp->front;
        qp->front = NULL;
        qp->rear = NULL;
        qp->length -= 1;
        return rp;
    }
    else
    {
        return NULL;
    }
}

/*
 * Clean the linked list queue
 * @param *qp - pointer to the queue
 */
void clean_queue(QUEUE *qp)
{
    clean(&(qp->front));
    qp->front = NULL;
    qp->rear = NULL;
    qp->length = 0;
}