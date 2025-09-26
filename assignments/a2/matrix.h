/*
* --------------------------------------------------
Project: 
File:    matrix.h
Author:  Mustafa Qasim
Version: 2025-09-23
--------------------------------------------------
*/

/**
 * Calculates the Euclidean norm (length) of a vector.
 * @param v Pointer to the vector.
 * @param n Number of elements in the vector.
 * @return The Euclidean norm of the vector.
 */
float norm(float *v, int n);

/**
 * Normalizes a vector (scales it to unit length).
 * @param vin Pointer to the input vector.
 * @param vout Pointer to the output vector (normalized).
 * @param n Number of elements in the vector.
 */
void normalize(const float *vin, float *vout, int n);

/**
 * Multiplies a matrix by a scalar value.
 * @param A Pointer to the input matrix.
 * @param scalar Scalar value to multiply.
 * @param B Pointer to the output matrix (result).
 * @param rows Number of rows in the matrix.
 * @param cols Number of columns in the matrix.
 */
void matrix_scalar_multiply(const float *A, float scalar, float *B, int rows, int cols);

/**
 * Computes the transpose of a matrix.
 * @param A Pointer to the input matrix (rows x cols).
 * @param B Pointer to the output matrix (cols x rows).
 * @param rows Number of rows in the input matrix.
 * @param cols Number of columns in the input matrix.
 */
void matrix_transpose(const float *A, float *B, int rows, int cols);

/**
 * Adds two matrices element-wise.
 * @param A Pointer to the first input matrix.
 * @param B Pointer to the second input matrix.
 * @param C Pointer to the output matrix (sum).
 * @param rows Number of rows in the matrices.
 * @param cols Number of columns in the matrices.
 */
void matrix_add(const float *A, const float *B, float *C, int rows, int cols);


/* Multiplies two matrices.
 * @param A Pointer to the first input matrix (rowsA x colsA).
 * @param B Pointer to the second input matrix (colsA x colsB).
 * @param C Pointer to the output matrix (rowsA x colsB).
 * @param rowsA Number of rows in matrix A.
 * @param colsA Number of columns in matrix A and rows in matrix B.
 * @param colsB Number of columns in matrix B.
 */
void matrix_multiply(const float *A, const float *B, float *C, int rowsA, int colsA, int colsB);