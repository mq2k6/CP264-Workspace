/*
* --------------------------------------------------
Project:
File:    avl.c
Author:  Mustafa Qasim
Version: 2025-11-10
--------------------------------------------------
*/

#include "avl.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

AVLNODE *avl_node(RECORD data)
{
    AVLNODE *ptr = (AVLNODE *)malloc(sizeof(AVLNODE));
    ptr->data = data;
    ptr->height = 1;
    ptr->left = ptr->right = NULL;
    return ptr;
}

/* Insert a node of given record data into AVL tree.
 *
 * @param rootp - pointer of pointer to tree root.
 * @param data  - record data for the new node.
 */
void avl_insert(AVLNODE **rootp, RECORD data)
{

    AVLNODE *root = *rootp;

    if ((*rootp) == NULL)
    {
        *rootp = avl_node(data);
        return;
    }

    int comp = strcmp((*rootp)->data.name, data.name);

    if (comp == 0)
    {
        if ((*rootp)->data.score > data.score)
        {
            avl_insert(&(*rootp)->right, data);
        }
        else
        {
            avl_insert(&(*rootp)->left, data);
        }
    }

    else if (comp < 0)
    {
        avl_insert(&(*rootp)->right, data);
    }

    else if (comp > 0)
    {
        avl_insert(&(*rootp)->left, data);
    }

    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));
    int bf = balance_factor((*rootp));

    if (bf == -2)
    {
        int bfR = balance_factor((*rootp)->right);

        if (bfR > 0)
        {
            (*rootp)->right = rotate_right((*rootp)->right);
            (*rootp) = rotate_left((*rootp));
        }
        else
        {
            (*rootp) = rotate_left((*rootp));
        }
    }

    else if (bf == 2)
    {
        int bfL = balance_factor((*rootp)->left);

        if (bfL < 0)
        {
            (*rootp)->left = rotate_left((*rootp)->left);
            (*rootp) = rotate_right((*rootp));
        }
        else
        {
            (*rootp) = rotate_right((*rootp));
        }
    }

    return;
}

/* Remove and return the node with the smallest data.name from the AVL. */
AVLNODE *extract_smallest_node(AVLNODE **rootp)
{
    AVLNODE *parent = NULL;
    AVLNODE *s = *rootp;
    while (s && s->left)
    {
        parent = s;
        s = s->left;
    }
    if (parent)
    {
        parent->left = s->right;
    }
    else
    {
        *rootp = s->right;
    }
    // Detach the smallest node from the tree to avoid dangling references.
    s->right = NULL;
    return s;
}

/* Delete a node of data.name matched with given key from AVL tree.
 *
 * @param rootp - pointer of pointer to tree root.
 * @param key -   key to match with data.name for deletion.
 */
void avl_delete(AVLNODE **rootp, char *key)
{

    AVLNODE *root = *rootp;

    if (root == NULL)
    {
        return;
    }

    int comp = strcmp(root->data.name, key);

    if (comp > 0)
    {
        avl_delete(&root->left, key);
    }
    else if (comp < 0)
    {
        avl_delete(&root->right, key);
    }
    else
    {

        // Node to be deleted found
        if (root->left == NULL && root->right == NULL)
        {
            free((*rootp));
            *rootp = NULL;
        }
        else if (root->left == NULL)
        {
            AVLNODE *temp = root->right;
            free(root);
            *rootp = temp;
        }
        else if (root->right == NULL)
        {
            AVLNODE *temp = root->left;
            free(root);
            *rootp = temp;
        }
        else
        {
            AVLNODE *smallest = extract_smallest_node(&root->right);
            root->data = smallest->data;
            free(smallest);
        }
    }

    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

    int bf = balance_factor((*rootp));

    if (bf == -2)
    {
        int bfR = balance_factor((*rootp)->right);

        if (bfR > 0)
        {
            (*rootp)->right = rotate_right((*rootp)->right);
            (*rootp) = rotate_left((*rootp));
        }
        else
        {
            (*rootp) = rotate_left((*rootp));
        }
    }

    else if (bf == 2)
    {
        int bfL = balance_factor((*rootp)->left);

        if (bfL < 0)
        {
            (*rootp)->left = rotate_left((*rootp)->left);
            (*rootp) = rotate_right((*rootp));
        }
        else
        {
            (*rootp) = rotate_right((*rootp));
        }
    }

    return;
}

/* Search AVL tree by key of the name field
 * @param root - pointer to tree root.
 * @param key - key to match with data.name for search
 * @return - node pointer if found, otherwise NULL
 */
AVLNODE *avl_search(AVLNODE *root, char *key)
{

    if (root)
    {

        int comp = strcmp(key, root->data.name);

        if (comp == 0)
        {
            return root;
        }
        else
        {
            if (root->right && comp > 0)
            {
                return avl_search(root->right, key);
            }

            if (root->left && comp < 0)
            {
                return avl_search(root->left, key);
            }
        }
    }

    return NULL;
}

/* This function clean AVL tree.
 * @param rootp - pointer of pointer of tree root.
 */
void avl_clean(AVLNODE **rootp)
{
    AVLNODE *root = *rootp;

    if (root)
    {
        if (root->left)
        {
            avl_clean(&root->left);
        }
        if (root->right)
        {
            avl_clean(&root->right);
        }
        free(root);
    }

    *rootp = NULL;
}

/* Get the height of AVL tree
 * @param np - pointer to the root of tree
 * @return - the the height value at root.
 */
int height(AVLNODE *root)
{
    return root != NULL ? root->height : 0;
}

/* Return the balance factor at the given node
 * @param np - pointer to the node of tree
 * @return - the balance factor a the node
 */
int balance_factor(AVLNODE *np)
{
    if (np)
    {
        int lh = height(np->left);
        int rh = height(np->right);
        return (lh - rh);
    }
    else
        return 0;
}

/* This function does the left rotation at a given node
 * @param np - pointer to the rotation node.
 * @return - the pointer to the replaced node.
 */
AVLNODE *rotate_left(AVLNODE *np)
{
    AVLNODE *tmp = np->right;
    np->right = tmp->left;
    tmp->left = np;

    np->height = 1 + (height(np->left) > height(np->right) ? height(np->left) : height(np->right));

    tmp->height = 1 + (height(tmp->left) > height(tmp->right) ? height(tmp->left) : height(tmp->right));

    return tmp;
}

/* This function does the right rotation at a given node
 * @param np - pointer to the rotation node.
 * @return - the pointer to the replaced node.
 */
AVLNODE *rotate_right(AVLNODE *root)
{
    AVLNODE *tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;

    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

    tmp->height = 1 + (height(tmp->left) > height(tmp->right) ? height(tmp->left) : height(tmp->right));

    return tmp;
}