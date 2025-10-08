/*
* --------------------------------------------------
Project:
File:    myrecord.c
Author:  Mustafa Qasim
Version: 2025-10-01
--------------------------------------------------
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "myrecord.h"
#include "mysort.h"

int cmp2(void *x, void *y)
{
    float b = ((RECORD *)x)->score;
    float a = ((RECORD *)y)->score;
    if (a > b)
        return 1;
    else if (a < b)
        return -1;
    else
        return 0;
}

/*
 * Convert a percentage grade to letter grade defined by percentage ranges
 * A+=[90, 100], A=[85, 90), A-=[80, 85), B+=[77, 80), B=[73, 77) B-=[70, 73),
 * C+=[67, 70), C=[63, 67), C-=[60, 63), D+=[57,60),D=[53,57),D=[50,53), F=[0,50).
 * Use binary search algorithm to find the corresponding letter grade.
 *
 * @param score -  percetage grade.
 *
 * @return - letter grade wrapped in GRADE structure type.
 */
GRADE grade(float score)
{

    char g[14][5] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "D-", "F"};
    int b[] = {100, 90, 85, 80, 77, 73, 70, 67, 63, 60, 57, 53, 50, 0};

    int left = 0;
    int right = 14;

    GRADE r = {"B-"};
    int i = 6;

    while (left < right)
    {
        if ((b[i - 1] > score && score >= b[i]))
        {
            if (score >= 90)
            {
                strcpy(r.letter_grade, g[0]);
                break;
            }
            else
            {
                strcpy(r.letter_grade, g[i - 1]);
                break;
            }
        }

        else if (score > b[i])
        {
            right = i;
            i = (right + left) / 2;
        }

        else
        {
            left = i;
            i = (right + left) / 2;
        }
    }

    return r;
}

/*
 *  Import record data from file and store name and store all record entries
 *  in the RECORD array passed by records, return the number of record count.
 *
 *  @param *fp -  FILE pointer to intput file.
 *  @param dataset - array of RECORD type to store record data.
 *  @return   - number of records
 */
int import_data(FILE *fp, RECORD *dataset)
{
    char delimiters[] = " ,\n\r";
    char line[100];
    int i = 0; // record counter
    char *token = NULL;
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        // use sscanf() get name string to dataset[i].name, float score to dataset[i].score
        sscanf(line, "%[^, ],%f", dataset[i].name, &dataset[i].score);
        // or use strtok to get name and score.
        // token = (char *) strtok(line, delimiters);
        // strcpy(dataset[i].name, token);
        // token = (char *) strtok(NULL, delimiters);
        sscanf(token, "%f", &dataset[i].score);
        i++;
    }
    return i;
}

/*
 *  Take the RECORD data array as input, compute the average score, standard deviation,
 *  median of the score values of the record data, and returns the STATS type value.
 *
 *  @param dataset -  input record data array.
 *  @param count -  the number of data record in dataset array.
 *  @return  -  stats value in STATS type.
 */
STATS process_data(RECORD *dataset, int count)
{

    STATS st = {0};

    if (count <= 0)
    {
        st.count = 0;
        st.mean = 0.0;
        st.stddev = 0.0;
        st.median = 0.0;
        return st;
    }

    st.count = count;

    float mean = 0;
    for (int i = 0; i < count; i++)
    {
        mean += dataset[i].score;
    }
    mean /= count;
    st.mean = mean;

    void *a[count];

    for (int i = 0; i < count; i++)
    {
        a[i] = &dataset[i].score;
    }

    quick_sort(a, 0, count - 1);

    float median = 0;
    if (count % 2 != 0)
    {
        median = *(float *)a[count / 2];
    }
    else
    {
        float val1 = *(float *)a[count / 2 - 1];
        float val2 = *(float *)a[count / 2];
        median = (val1 + val2) / 2.0;
    }
    st.median = median;

    float std = 0;
    for (int i = 0; i < count; i++)
    {
        std += (dataset[i].score - mean) * (dataset[i].score - mean);
    }

    float stddev = sqrt(std / count);
    st.stddev = stddev;

    return st;
}

/*
 *  This function takes output file named outfilename, RECORD array records,
 *  and stats as inputs, prepare and write report of stats and grade to files.
 *  The records in report file are sorted in decreasing of scores.
 *
 *  @param *fp -  FILE pointer to output file.
 *  @param *dataset - pointer to dataset array.
 *  @param stats - the stats value to be used in report.
 *  @return - returns 1 if successful; 0 if count < 1
 */
int report_data(FILE *fp, RECORD *dataset, STATS stats)
{
    int n = stats.count;

    if (n < 1)
    {
        return 0;
    }
    else
    {
        RECORD *p[n];
        for (int i = 0; i < n; i++)
        {
            p[i] = &dataset[i];
        }

        my_sort((void *)p, 0, n - 1, cmp2);

        fprintf(fp, "stats:value\ncount:%d\nmean:%.1f\nstddev:%.1f\nmedian:%.1f\n", n, stats.mean, stats.stddev, stats.median);
        fprintf(fp, "\nname:score,grade\n");
        for (int i = 0; i < n; i++)
        {
            fprintf(fp, "%s: %.1f,%s\n", p[i]->name, p[i]->score, grade(p[i]->score).letter_grade);
        }
        return 1;
    }
}
