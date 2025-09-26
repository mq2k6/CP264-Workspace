/*
* --------------------------------------------------
Project:
File:    fibonacci.c
Author:  Mustafa Qasim
Version: 2025-09-22
--------------------------------------------------
*/

#include "fibonacci.h"

/**
 * Iteratively compute Fibonacci number F(n).
 *
 * @param n - int type
 * @return - F(n) if not overflow
             otherwise -1.
 */
int iterative_fibonacci(int n)
{

    int f1 = 0;
    int f2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (f1 + f2 == 0)
        {
            f2 += 1;
        }
        else
        {
            int temp = f2;
            f2 += f1;
            f1 = temp;
        }

        if (f2 < 0)
        {
            return -1;
        }
    }

    return f2;
}

/**
 * Recursively compute Fibonacci number F(n).
 *
 * @param n - int type
 * @return - F(n) if not overflow
             otherwise -1.
 */
int recursive_fibonacci(int n)
{

    int f1 = 0;
    int f2 = 1;
    int sum = 0;

    if (n < 2)
    {
        return n;
    }
    else
    {
        sum = recursive_fibonacci(n - 2) + recursive_fibonacci(n - 1);
    }

    if (sum < 0)
    {
        return -1;
    }
    else
    {
        return sum;
    }
}

/**
 * Compute Fibonacci number F(n) using Bottom-Up Dynamic Programming.
 *
 * @param *f - int type pointer, n - int type
 * @return - F(n) if not overflow
             otherwise -1.
 */
int dpbu_fibonacci(int *f, int n)
{

    f[0] = 0;
    f[1] = 1;

    if (n < 2)
    {
        return f[n];
    }

    for (int i = 2; i <= n; i++)
    {
        f[i] = f[i - 2] + f[i - 1];
    }

    if (f[n] < 0)
    {
        return -1;
    }
    else
    {
        return f[n];
    }
}

/**
 * Compute Fibonacci number F(n) using Top-Down Dynamic Programming.
 *
 * @param *f - int type pointer, n - int type
 * @return - F(n) if not overflow
             otherwise -1.
 */
int dptd_fibonacci(int *f, int n)
{
    f[0] = 0;
    f[1] = 1;
    if (n <= 1)
    {
        return f[n];
    }
    else
    {
        f[n] = dptd_fibonacci(f, n - 2) + dptd_fibonacci(f, n - 1);
        if (f[n] < 0)
        {
            return -1;
        }
        else
        {
            return f[n];
        }
    }
}