/*
* --------------------------------------------------
Project: a1q2
File:    powersum.c
Author:  Mustafa Qasim
Version: 2025-09-08
--------------------------------------------------
*/

#include "powersum.h"

/**
 * Depect if overflow in power computing of b to power of n
 *
 * @param b - the base
 * @param n - the exponent
 * @return - 1 if overflow happens, 0 otherwise
 */
int power_overflow(int b, int n)
{
    //calculate power
    int p = b;
    for (int i = 2; i < n; i++)
    {
        b *= p;
    }

    //check overflow
    int temp = p * b;
    if (temp / b != p)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * Compute and return b to power of n.
 *
 * @param b - the base
 * @param n - the exponent
 * @return - b to the power of n if no overflow happens, 0 otherwise
 */
int mypower(int b, int n)
{   

    int power;
    if (power_overflow(b, n) == 0) //only calculate if no overflow
    {
        int p = b;
        for (int i = 1; i < n; i++)
        {
            b *= p;
        }
        power = b;
    }
    else
    {
        power = 0;
    }
    return(power);
}

/**
 * Compute and return the sum of powers.
 *
 * @param b - the base
 * @param n - the exponent
 * @return -  the sum of powers if no overflow happens, 0 otherwise
 */
int powersum(int b, int n)
{   
    int ans;
    if (power_overflow(b, n) != 1)  //check overflow
    {
        int sum = 1;  //start at b^0
        for (int i = 1; i < n + 1; i++)
        {
            sum += mypower(b, i);   //add next power to total sum
        };

        ans = sum;
    }
    else
    {
        ans = 0;
    };

    return(ans);
};