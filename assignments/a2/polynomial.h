/*
* --------------------------------------------------
Project: 
File:    polynomial.h
Author:  Mustafa Qasim
Version: 2025-09-22
--------------------------------------------------
*/

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
float horner(float *p, int n, float x);

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
void derivative(float *p, float *d, int n);

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
float newton(float *p, int n, float x0);