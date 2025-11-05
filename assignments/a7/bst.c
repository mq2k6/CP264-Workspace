/*
* --------------------------------------------------
Project:
File:    bst.c
Author:  Mustafa Qasim
Version: 2025-11-04
--------------------------------------------------
*/

#include "bst.h"

/* This function creates BSTNODE node with given RECORD data
 * using malloc() and return the new node pointer.
 */
BSTNODE *bst_node(RECORD data)
{

    BSTNODE *node = (BSTNODE *)malloc(sizeof(BSTNODE));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

/* Search the BST by search key matching with data.name
 *
 * @param root - pointer to tree root.
 * @param key - string of search key
 *
 * @return - pointer to matched node if found, otherwise NULL
 */
BSTNODE *bst_search(BSTNODE *root, char *key)
{
    if (root)
    {
        if (strcmp(root->data.name, key) == 0)
        {
            return root;
        }
        else if (strcmp(root->data.name, key) < 0)
        {
            return bst_search(root->left, key);
        }
        else
        {
            return bst_search(root->right, key);
        }
    }
}

/* Insert a node of given record data into BST.
 *
 * @param rootp - pointer of pointer to tree root.
 * @param data  -  record data for the new node.
 *
 */
void bst_insert(BSTNODE **rootp, RECORD data)
{

    BSTNODE *root = *rootp;

    if (root == NULL)
    {
        *rootp = bst_node(data);
    }
    else
    {

        if (strcmp(root->data.name, data.name) < 0)
        {
            if (root->left == NULL)
            {
                root->left = bst_node(data);
            }
            else
            {
                bst_insert(&root->left, data);
            }
        }
        else
        {
            if (root->right == NULL)
            {
                root->right = bst_node(data);
            }
            else
            {
                bst_insert(&root->right, data);
            }
        }
    }
}

/* Delete a node of data.name matched with given key.
 *
 * @param rootp - pointer of pointer to tree root.
 * @param key -   key to match with data.name for deletion.
 */
void bst_delete(BSTNODE **rootp, char *key)
{
    BSTNODE *root = *rootp;

    if (root == NULL)
    {
        return;
    }

    if (strcmp(root->data.name, key) < 0)
    {
        bst_delete(&root->left, key);
    }
    else if (strcmp(root->data.name, key) > 0)
    {
        bst_delete(&root->right, key);
    }
    else
    {
        // Node to be deleted found
        if (root->left == NULL && root->right == NULL)
        {
            // Case 1: No children
            free(root);
            *rootp = NULL;
        }
        else if (root->left == NULL)
        {
            // Case 2: One child (right)
            BSTNODE *temp = root->right;
            free(root);
            *rootp = temp;
        }
        else if (root->right == NULL)
        {
            // Case 2: One child (left)
            BSTNODE *temp = root->left;
            free(root);
            *rootp = temp;
        }
        else
        {
            // Case 3: Two children
            BSTNODE *smallest = extract_smallest_node(&root->right);
            root->data = smallest->data;
            free(smallest);
        }
    }
}
/* This function cleans the BST passed by pointer of root pointer.
 * @param rootp - pointer to pointer of a tree node.
 */
void bst_clean(BSTNODE **rootp)
{

    BSTNODE *root = *rootp;

    if (root->left)
    {
        bst_clean(&root->left);
    }
    if (root->right)
    {
        bst_clean(&root->right);
    }

    *rootp = NULL;
    free(root);
}

/* Remove and return the node with the smallest data.name from the BST. */
BSTNODE *extract_smallest_node(BSTNODE **rootp)
{
    BSTNODE *parent = NULL;
    BSTNODE *s = *rootp;
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