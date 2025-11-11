/*
* --------------------------------------------------
Project:
File:    myrecord_avl.c
Author:  Mustafa Qasim
Version: 2025-11-11
--------------------------------------------------
*/

#include "myrecord_avl.h"
#include <stdio.h>
#include <stdlib.h>

/*  Merge source AVL tree into destination AVL tree. No change to source tree.
 *  @parame rootp_dest   - pointer to pointer of root of destination tree
 *  @parame rootp_source - pointer to pointer of root of source tree
 */
void avl_merge(AVLNODE **rootp_dest, AVLNODE **rootp_source)
{
    if (*rootp_source != NULL)
    {
        avl_insert((rootp_dest), (*rootp_source)->data);

        avl_merge((rootp_dest), &(*rootp_source)->left);
        avl_merge((rootp_dest), &(*rootp_source)->right);
    }
}

/*  Merge source AVLDS to destination AVLDS, use aggregation algorithm to
 *  compute the stats info, can clean source AVLDS.
 *  @parame source - pointer to the source AVLDS
 *  @parame dest - pointer to the destination AVLDS
 */
void avlds_merge(AVLDS *dest, AVLDS *source)
{
    printf("%f %f", source->stddev, dest->stddev);
    while (source->root != NULL)
    {
        add_record(dest, source->root->data);
        remove_record(source, source->root->data.name);
    }

    printf("%f %f", source->stddev, dest->stddev);
    avlds_clean(source);
}

/*  Clean its AVL tree and set count=0, mean=0, stddev=0
 *  @parame ds - pointer to the AVLDS
 */
void avlds_clean(AVLDS *ds)
{
    avl_clean(&ds->root);
    ds->count = 0;
    ds->mean = 0;
    ds->stddev = 0;
}

// The following two functions are similar to that of A7Q3.
void add_record(AVLDS *tree, RECORD data)
{
    if (avl_search(tree->root, data.name) == NULL)
    {
        avl_insert(&(tree->root), data);
        int count = tree->count;
        float mean = tree->mean;
        float stddev = tree->stddev;
        tree->count = count + 1;
        tree->mean = (mean * count + data.score) / (count + 1.0);
        tree->stddev = sqrt(data.score * data.score / (count + 1.0) + (stddev * stddev + mean * mean) * (count / (count + 1.0)) - tree->mean * tree->mean);
    }
    else
    {
        printf("record exits");
    }
}

void remove_record(AVLDS *ds, char *name)
{
    AVLNODE *ptr = avl_search(ds->root, name);
    avl_delete(&ds->root, name);

    if (ds->count == 1)
    {
        ds->count = 0;
        ds->mean = 0;
        ds->stddev = 0;
    }
    else
    {

        float newMean = (ds->mean * ds->count - ptr->data.score) / (ds->count - 1);

        float newStddev = sqrt(
            (
                (pow(ds->stddev, 2) + pow(ds->mean, 2)) * ds->count - pow(ptr->data.score, 2) - (ds->count - 1) * pow(newMean, 2)) /
            (ds->count - 1));

        ds->count -= 1;
        ds->mean = newMean;
        ds->stddev = newStddev;
    }
}