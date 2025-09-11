/*
* --------------------------------------------------
Project: a1q3
File:    mymortgage.c
Author:  Mustafa Qasim
Version: 2025-09-08
--------------------------------------------------
*/

#include "mymortgage.h"
#include <math.h>

// principal  * r * pow(1 + r, n) / (pow(1 + r, n) - 1)

/**
 * Compute the monthly payment of given mortgage princile, annual interest rate (%), and mortgage years. 
 *
 * @param principal_amount - float type.
 * @param annual_interest_rate - value of parcentage rate, e.g. 5 means 5%, float type.
 * @param years - number of mortgage year, int type.
 * @return - monthly payment, float type.
 */
float monthly_payment(float principal_amount, float annual_interest_rate, int years) {
    float monthly_interest_rate = (annual_interest_rate/100)/12;
    int months = years * 12;

    return(principal_amount * (monthly_interest_rate) * pow(1 + monthly_interest_rate, months) / (pow(1+monthly_interest_rate, months) - 1));
}


/**
 * Determine the total payment of loan given mortgage princile, annual interest rate (%), and mortgage years. 
 *
 * @param principal_amount - float type.
 * @param annual_interest_rate - value of parcentage rate, e.g. 5 means 5%, float type.
 * @param years - number of mortgage year, int type.
 * @return - the total payment of the loan, float type.
 */
float total_payment(float principal_amount, float annual_interest_rate, int years) {
    return(monthly_payment(principal_amount, annual_interest_rate, years) * 12 * years);
}


/**
 * Determine the total interested payed for the loan given mortgage princile, annual interest rate (%), and mortgage years. 
 *
 * @param principal_amount - float type.
 * @param annual_interest_rate - value of parcentage rate, e.g. 5 means 5%, float type.
 * @param years - number of mortgage year, int type.
 * @return - the total interest payed by the end of paying off the loan, float type.
 */
float total_interest(float principal_amount, float annual_interest_rate, int years) {
    
    return(total_payment(principal_amount, annual_interest_rate, years) - principal_amount);
}