/*
* --------------------------------------------------
Project: a1q3
File:    mymortgage.h
Author:  Mustafa Qasim
Version: 2025-09-08
--------------------------------------------------
*/

#include <stdio.h>

#ifndef MYMORTGAGE_H
#define MYMORTGAGE_H

float monthly_payment(float principal_amount, float annual_interest_rate, int years);

float total_payment(float principal_amount, float annual_interest_rate, int years);

float total_interest(float principal_amount, float annual_interest_rate, int years);

#endif