/*
* --------------------------------------------------
Project:
File:    myrecord_bst.c
Author:  Mustafa Qasim
Version: 2025-11-04
--------------------------------------------------
*/

#include "myrecord_bst.h"
#include <math.h>

/* Add a record data into the BSTDS and update its statistic fields
 * using incremental/online algorithm.
 * @parame ds - pointer to the BSTDS.
 * @parama record - RECORD data to be added.
 */
void add_record(BSTDS *ds, RECORD record)
{
    bst_insert(&ds->root, record);

    if (ds->count == 0)
    {
        ds->count = 1;
        ds->mean = (float)record.score;
        ds->stddev = (float)0;
    }
    else
    {
        float newMean = ((float)1 / (ds->count + 1)) * ((ds->count * ds->mean) + record.score);

        float newStddev = sqrt(((float)1 / (ds->count + 1)) * (ds->count * (pow(ds->stddev, 2) + pow(ds->mean, 2)) + pow(record.score, 2)) - pow(newMean, 2));

        ds->count += 1;
        ds->mean = newMean;
        ds->stddev = newStddev;
    }
}

/* Delete a node from BSTDA with data.name matching with the given name
 * and stats fields using incremental/online algorithm.
 * @parame ds - pointer to the BSTDS.
 * @parama name - node data.name to be removed.
 */
void remove_record(BSTDS *ds, char *name)
{
    BSTNODE *ptr = bst_search(ds->root, name);
    bst_delete(&ds->root, name);

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
        ds->stddev = ds->count == 1 ? 0.0 / 0.0 : newStddev;
    }
}

/* Clean the BSTDS and reset count, mean, stddev
 * @parame ds - pointer to the BSTDS.
 */
void bstds_clean(BSTDS *ds)
{
    if (ds == NULL)
    {
        return;
    }
    ds->count = 0;
    ds->mean = 0;
    ds->stddev = 0;
}