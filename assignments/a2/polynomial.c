/*
* --------------------------------------------------
Project:
File:    polynomial.c
Author:  Mustafa Qasim
Version: 2025-09-22
--------------------------------------------------
*/

#include <stdio.h>
#include "polynomial.h"
#define EPSILON 1e-6
#define MAXCOUNT 100

/**
 * Compute and return the value of a polynomial of degree (n-1):
 *   p(x) = p[0]*x^{n-1} + p[1]*x^{n-2} + ... + p[n-2]*x^1 + p[n-1]*x^0
 * using Horner's algorithm (see: https://en.wikipedia.org/wiki/Horner%27s_method).
 *
 * @param p Pointer to the array of coefficients (length n).
 * @param n Number of coefficients (degree + 1).
 * @param x Value at which to evaluate the polynomial.
 * @return The computed value p(x).
 */
float horner(float *p, int n, float x)
{
    float r = 0;
    for (int i = 0; i < n; i++)
        r = r * x + p[i];
    return r;
}

/**
 * Compute the derivative of a polynomial of degree (n-1):
 *   p(x) = p[0]*x^{n-1} + p[1]*x^{n-2} + ... + p[n-2]*x^1 + p[n-1]*x^0
 * and store the coefficients of the derivative polynomial in array d.
 * The derivative is:
 *   p'(x) = (n-1)*p[0]*x^{n-2} + (n-2)*p[1]*x^{n-3} + ... + p[n-2]*x^0
 *
 * @param p Pointer to the array of input polynomial coefficients (length n).
 * @param d Pointer to the array for output derivative coefficients (length n-1).
 * @param n Number of coefficients in the input polynomial.
 */
void derivative(float *p, float *d, int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        float coeff = p[n - i - 2];
        d[i] = coeff * p[i];
    }
}

/**
 * Compute an approximate real root x of polynomial p(x) using Newton's method
 * (see: https://en.wikipedia.org/wiki/Newton%27s_method).
 * Uses a tolerance of 1e-6 and a maximum of 100 iterations.
 *
 * @param p Pointer to the array of input polynomial coefficients (length n).
 * @param n Number of coefficients in the input polynomial.
 * @param x0 Initial guess for the root.
 * @return The computed root if found; otherwise, returns x0.
 */
float newton(float *p, int n, float x0)
{
    float x = x0;
    float px = horner(p, n, x);
    float d[n - 1];
    int iter = 0;

    derivative(p, d, n);

    while (fabs(px) > EPSILON && iter++ < MAXCOUNT)
    {
        float dx = horner(d, n - 1, x);
        x0 = x;
        x = x0 - (px / dx);
        px = horner(p, n, x);
    }

    return x;
}