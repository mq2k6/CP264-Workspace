/*
* --------------------------------------------------
Project:
File:    matrix.c
Author:  Mustafa Qasim
Version: 2025-09-23
--------------------------------------------------
*/

#include <math.h>
#include "matrix.h"

/**
 * Calculates the Euclidean norm (length) of a vector.
 * @param v Pointer to the vector.
 * @param n Number of elements in the vector.
 * @return The Euclidean norm of the vector.
 */
float norm(float *v, int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += pow(v[i], 2);
    }

    return sqrt(sum);
}

/**
 * Normalizes a vector (scales it to unit length).
 * @param vin Pointer to the input vector.
 * @param vout Pointer to the output vector (normalized).
 * @param n Number of elements in the vector.
 */
void normalize(const float *vin, float *vout, int n)
{
    for (int i = 0; i < n; i++)
    {
        vout[i] = vin[i] / norm(vin, n);
    }
}

/**
 * Multiplies a matrix by a scalar value.
 * @param A Pointer to the input matrix.
 * @param scalar Scalar value to multiply.
 * @param B Pointer to the output matrix (result).
 * @param rows Number of rows in the matrix.
 * @param cols Number of columns in the matrix.
 */
void matrix_scalar_multiply(const float *A, float scalar, float *B, int rows, int cols)
{
    for (int i = 0; i < rows * cols; i++)
    {
        B[i] = A[i] * scalar;
    }
}

/**
 * Computes the transpose of a matrix.
 * @param A Pointer to the input matrix (rows x cols).
 * @param B Pointer to the output matrix (cols x rows).
 * @param rows Number of rows in the input matrix.
 * @param cols Number of columns in the input matrix.
 */
void matrix_transpose(const float *A, float *B, int rows, int cols)
{
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            B[j + i * rows] = A[i + j * cols];
        }
    }
}

/**
 * Adds two matrices element-wise.
 * @param A Pointer to the first input matrix.
 * @param B Pointer to the second input matrix.
 * @param C Pointer to the output matrix (sum).
 * @param rows Number of rows in the matrices.
 * @param cols Number of columns in the matrices.
 */
void matrix_add(const float *A, const float *B, float *C, int rows, int cols)
{
    for (int a = 0; a < rows * cols; a++)
    {
        C[a] = B[a] + A[a];
    }
}

/* Multiplies two matrices.
 * @param A Pointer to the first input matrix (rowsA x colsA).
 * @param B Pointer to the second input matrix (colsA x colsB).
 * @param C Pointer to the output matrix (rowsA x colsB).
 * @param rowsA Number of rows in matrix A.
 * @param colsA Number of columns in matrix A and rows in matrix B.
 * @param colsB Number of columns in matrix B.
 */
void matrix_multiply(const float *A, const float *B, float *C, int rowsA, int colsA, int colsB)
{
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            float tempsum = 0;
            for (int k = 0; k < colsA; k++)
            {
                tempsum += (A[k + i * colsA] * B[j + k * colsB]);
            }
            C[j + i * colsB] = tempsum;
        }
    }
}