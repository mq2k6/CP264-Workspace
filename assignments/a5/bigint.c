/*
* --------------------------------------------------
Project:
File:    bigint.c
Author:  Mustafa Qasim
Version: 2025-10-16
--------------------------------------------------
*/

#include "bigint.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Creates and returns BIGINT object by converting the digit string.
 */
BIGINT bigint(char *p)
{
    BIGINT bn = {0};
    if (p == NULL)
        return bn;
    else if (!(*p >= '0' && *p <= '9'))
    { // not begin with digits
        return bn;
    }
    else if (*p == '0' && *(p + 1) == '\0')
    { // just "0"
        dll_insert_end(&bn, dll_node(*p - '0'));
        return bn;
    }
    else
    {
        while (*p)
        {
            if (*p >= '0' && *p <= '9')
            {
                dll_insert_end(&bn, dll_node(*p - '0'));
            }
            else
            {
                dll_clean(&bn);
                break;
            }
            p++;
        }
        return bn;
    }
}

/*
 * Add two BIGINT operants and returns the sum in BIGINT type.
 * @param oprand1  - first operand of BIGINT type.
 * @param oprand2  - second operand of BIGINT type.
 * @return - the sum of oprand1 and oprand2 in BIGINT type.
 */
BIGINT bigint_add(BIGINT oprand1, BIGINT oprand2)
{
    BIGINT result = {0, NULL, NULL};
    NODE *a = oprand1.end;
    NODE *b = oprand2.end;
    int carry = 0;

    while (a || b)
    {
        int sum = carry;

        if (a)
            sum += a->data;
        if (b)
            sum += b->data;

        dll_insert_start(&result, dll_node(sum % 10));
        carry = sum / 10;

        if (a)
            a = a->prev;
        if (b)
            b = b->prev;
    }

    if (carry > 0)
    {
        dll_insert_start(&result, dll_node(carry));
    }

    return result;
}

/*
 * Compute and return Fibonacci(n)
 * @param n - input positive integer
 * @return  - Fibonacci(n) in BIGINT type
 */
BIGINT bigint_fibonacci(int n)
{
    // Initialize fib list with F(0) = 0 and F(1) = 1
    BIGINT fib0 = {0, NULL, NULL};
    BIGINT fib1 = {0, NULL, NULL};
    dll_insert_end(&fib0, dll_node(0));
    dll_insert_end(&fib1, dll_node(1));

    if (n == 0) return fib0;
    if (n == 1) return fib1;

    BIGINT result;

    for (int i = 2; i <= n; i++)
    {
        result = bigint_add(fib0, fib1);

        // Shift fib0 and fib1 forward
        dll_clean(&fib0);
        fib0 = fib1;
        fib1 = result;
    }

    return result;
}
