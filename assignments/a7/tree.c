/*
* --------------------------------------------------
Project:
File:    tree.c
Author:  Mustafa Qasim
Version: 2025-11-04
--------------------------------------------------
*/

#include "tree.h"

/* Compute and return the TPROPS value of a tree.
 * @param root - pointer to the root of a tree
 * @return - number of nodes and height in TPROPS type.
 */
TPROPS tree_property(TNODE *root)
{
    TPROPS tree = {0};
    if (!root)
    {
        return tree;
    }

    TPROPS rtL = tree_property(root->left);
    TPROPS rtR = tree_property(root->right);

    tree.order = 1 + rtL.order + rtR.order;
    tree.height = 1 + (rtL.height > rtR.height ? rtL.height : rtR.height);

    return tree;
}

/* Display the node data of the tree in pre-order and format "%c ".
 *
 *  @param root - pointer to the root of a tree
 */
void preorder(TNODE *root)
{
    if (root)
    {
        printf("%c ", root->data);
        if (root->left)
        {
            preorder(root->left);
        }
        if (root->right)
        {
            preorder(root->right);
        }
    }
}

/* Display the node data of the tree in in-order and format "%c".
 *
 *  @param root - pointer to the root of a tree
 */
void inorder(TNODE *root)
{
    if (root)
    {
        if (root->left)
        {
            inorder(root->left);
        }
        printf("%c ", root->data);
        if (root->right)
        {
            inorder(root->right);
        }
    }
}

/* Display the node data of the tree in post-order and format "%c ".
 *
 *  @param root - pointer to the root of a tree
 */
void postorder(TNODE *root)
{
    if (root)
    {
        if (root->left)
        {
            postorder(root->left);
        }
        if (root->right)
        {
            postorder(root->right);
        }
        printf("%c ", root->data);
    }
}

/* Display the node data of the tree in breadth-first-order and format "%c ".
 * Required to use auxiliary queue and iterative algorithm.
 *
 *  @param root - pointer to the root of a tree
 */
void bforder(TNODE *root)
{
    if (root)
    {
        QUEUE seen = {0};
        TNODE *p = root;

        enqueue(&seen, p);

        while (seen.front)
        {
            p = dequeue(&seen);
            printf("%c ", p->data);
            if (p->left)
            {
                enqueue(&seen, p->left);
            }
            if (p->right)
            {
                enqueue(&seen, p->right);
            }
        }
    }
}

/* Search by key using breadth-first-search algorithm
 * Required to use auxiliary queue and iterative algorithm.
 *
 *  @param root - pointer to the root of a tree
 *  @param key -  search key
 *
 *  @return  - the found node pointer if found, otherwise NULL
 */
TNODE *bfs(TNODE *root, char key)
{

    if (root)
    {
        QUEUE seen = {0};
        enqueue(&seen, root);

        while (seen.front)
        {
            TNODE *c = dequeue(&seen);

            if (c->data == key)
            {
                return c;
            }

            if (c->left)
            {
                enqueue(&seen, c->left);
            }
            if (c->right)
            {
                enqueue(&seen, c->right);
            }
        }
    }

    return NULL;
}

/* Search by key using depth-first-search algorithm.
 * Required to use auxiliary queue and iterative algorithm.
 *
 *  @param root - pointer to the root of a tree
 *  @param key -  search key
 *
 *  @return  - the found node pointer if fount, otherwise NULL
 */
TNODE *dfs(TNODE *root, char key)
{

    if (root)
    {
        STACK seen = {0};
        push(&seen, root);

        while (seen.top)
        {
            TNODE *c = pop(&seen);

            if (c->data == key)
            {
                return c;
            }
            
            if (c->right)
            {
                push(&seen, c->right);
            }
            if (c->left)
            {
                push(&seen, c->left);
            }
        }
        return NULL;
    }
}

// The following functions are given in a7 help.

/* Create a TNODE node and sets the data to value and returns the pointer.
 * Use malloc()
 */
TNODE *tree_node(char val)
{
    TNODE *node = malloc(sizeof(*node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* This function cleans a tree.
 * @param rootp - pointer of pointer to the tree root
 */
void clean_tree(TNODE **rootp)
{
    TNODE *p = *rootp;
    if (p)
    {
        if (p->left)
            clean_tree(&p->left);
        if (p->right)
            clean_tree(&p->right);
        free(p);
    }
    *rootp = NULL;
}

/* This function creates a new node of given value and inserts it into a tree
 * at the first available position in order of breadth-first and left to right.
 *
 * @param rootp - pointer of pointer to the tree node.
 * @param val - data for the new node.
 */
void insert_tree(TNODE **rootp, char val) {
    if (*rootp == NULL) {
        *rootp = tree_node(val);
    } else {
        QUEUE queue = { 0 };
        TNODE *p;
        enqueue(&queue, *rootp);
        while (queue.front) {
            p = dequeue(&queue);
            if (p->left == NULL) {
                p->left = tree_node(val);
                break;
            } else {
                enqueue(&queue, p->left);
            }

            if (p->right == NULL) {
                p->right = tree_node(val);
                break;
            } else {
                enqueue(&queue, p->right);
            }
        }
    }
}