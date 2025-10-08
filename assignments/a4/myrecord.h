/*
* --------------------------------------------------
Project: 
File:    myrecord.h
Author:  Mustafa Qasim
Version: 2025-10-01
--------------------------------------------------
*/

#ifndef MYRECORD_H
#define MYRECORD_H 
#include <stdio.h>

typedef struct {
  char name[20];
  float score;
} RECORD;

typedef struct {
  int count;
  float mean;
  float stddev;
  float median;
} STATS;

typedef struct {
  char letter_grade[3];
} GRADE;

GRADE grade(float score);

int import_data(FILE *fp, RECORD *dataset); 

STATS process_data(RECORD *dataset, int count);

int report_data(FILE *fp,  RECORD *dataset, STATS stats);

#endif