/*
* --------------------------------------------------
Project: 
File:    bigint.h
Author:  Mustafa Qasim
Version: 2025-10-16
--------------------------------------------------
*/

#ifndef BIGINT_H
#define BIGINT_H
#include "dllist.h"

typedef DLL BIGINT;
BIGINT bigint(char *digitstr);
BIGINT bigint_add(BIGINT oprand1, BIGINT oprand2);
BIGINT bigint_fibonacci(int n);

#endif