#ifndef _SPARSE_MATRIX_H_
#define _SPARSE_MATRIX_H_

#include "Node.h"

typedef struct SparseMatrix SparseMatrix;

/**
 * @brief allocates space for a sparse matrix structure
 * 
 * @param row quantity of rows in the matrix
 * @param column quantity of columns in the matrix
 * @return SparseMatrix* 
 */
SparseMatrix *sparse_matrix_construct(int row, int column);

/**
 * @brief frees space of a sparse matrix structure
 * 
 * @param matrix a sparse matrix structure
 */
void sparse_matrix_destroy(SparseMatrix *matrix);

/**
 * @brief adds an element in the position (row, column) of a sparse matrix
 * 
 * @param matrix a sparse matrix structure
 * @param value the value of the element
 * @param row row index of the element
 * @param column column index of the element
 */
void sparse_matrix_add_element(SparseMatrix *matrix, data_type value, int row, int column);

/**
 * @brief prints a sparse matrix - (row, column) = value
 * 
 * @param matrix a sparse matrix structure
 */
void sparse_matrix_print(SparseMatrix *matrix);

/**
 * @brief prints a sparse matrix in the dense format, printing 0's in positions that contain a NULL node
 * 
 * @param matrix a sparse matrix structure
 */
void sparse_matrix_dense_print(SparseMatrix* matrix);

/**
 * @brief returns the value of the element in a position (row, column) of a sparse matrix
 * 
 * @param matrix a sparse matrix structure
 * @param row row index of the element
 * @param column column index of the element
 * @return data_type the value of the element
 */
data_type sparse_matrix_get(SparseMatrix *matrix, int row, int column);

/**
 * @brief returns the sum of two sparse matrices
 * 
 * @param matrix_1 a sparse matrix structure
 * @param matrix_2 a sparse matrix structure
 * @return SparseMatrix* the sum of the two matrices
 */
SparseMatrix *sparse_matrix_sum(SparseMatrix *matrix_1, SparseMatrix *matrix_2);

/**
 * @brief returns a matrix multiplied by a scalar value
 * 
 * @param matrix a sparse matrix structure
 * @param scalar a scalar value
 * @return SparseMatrix* the matrix multiplied by a scalar as a new sparse matrix
 */
SparseMatrix *sparse_matrix_scalar_multiplication(SparseMatrix* matrix, int scalar);

/**
 * @brief returns the multiplication of two matrices
 * 
 * @param matrix_1 a sparse matrix structure
 * @param matrix_2 a sparse matrix structure
 * @return SparseMatrix* the multiplication of two matrices as a new sparse matrix
 */
SparseMatrix *sparse_matrix_multiply(SparseMatrix *matrix_1, SparseMatrix *matrix_2);

/**
 * @brief returns the multiplication element by element of two matrices
 * 
 * @param matrix_1 a sparse matrix structure
 * @param matrix_2 a sparse matrix structure
 * @return SparseMatrix* the multiplication element by element of two matrices as a new sparse matrix
 */
SparseMatrix *sparse_matrix_per_element_multiply(SparseMatrix *matrix_1, SparseMatrix *matrix_2);

/**
 * @brief returns the transpose of a sparse matrix
 * 
 * @param matrix a sparse matrix structure
 * @return SparseMatrix* the transpose of a matrix as a new sparse matrix
 */
SparseMatrix *sparse_matrix_transpose(SparseMatrix *matrix);

/**
 * @brief returns a sparse matrix with two rows swapped
 * 
 * @param matrix a sparse matrix structure
 * @param row_1 a row to be swapped
 * @param row_2 a row to be swapped
 * @return SparseMatrix* a new sparse matrix with the two rows swapped
 */
SparseMatrix *sparse_matrix_row_swap(SparseMatrix *matrix, int row_1, int row_2);

/**
 * @brief returns a sparse matrix with two columns swapped
 * 
 * @param matrix a sparse matrix structure
 * @param column_1 a column to be swapped
 * @param column_2 a column to be swapped
 * @return SparseMatrix* a new sparse matrix with two columns swapped
 */
SparseMatrix *sparse_matrix_column_swap(SparseMatrix *matrix, int column_1, int column_2);

/**
 * @brief saves a sparse matrix in a binary file
 * 
 * @param matrix a sparse matrix structure
 * @param file_name name of the binary file
 */
void sparse_matrix_save_binary(SparseMatrix *matrix, char* file_name);

/**
 * @brief reads a sparse matrix from a binary file
 * 
 * @param file_name name of the binary file
 * @return SparseMatrix* returns the sparse matrix of the binary file
 */
SparseMatrix *sparse_matrix_read_binary(char* file_name);

/**
 * @brief returns a slice cutted in the positions (row_1, column_1), (row_2, column_2) of the sparse matrix.\n
 * If row_1 or column_1 are less than the row/column size of the matrix, then it will be created a row/column with zeros/NULL nodes.\n
 * The same goes for row_2 and column_2 if they are greater than the row/column size of the matrix
 * 
 * @param matrix a sparse matrix structure
 * @param row_1 the row of the first position that determinates the slice
 * @param column_1 the column of the first position that determinates the slice
 * @param row_2 the row of the second position that determinates the slice
 * @param column_2 the column of the second position that determinates the slice
 * @return SparseMatrix* a slice of the matrix as a new sparse matrix
 */
SparseMatrix *sparse_matrix_slice(SparseMatrix *matrix, int row_1, int column_1, int row_2, int column_2);

/**
 * @brief calculates the convolution between a kernel and a sparse matrix
 * 
 * @param matrix a sparse matrix structure
 * @param kernel a convolution matrix
 * @return SparseMatrix* returns the convolution matrix
 */
SparseMatrix *sparse_matrix_convolution(SparseMatrix *matrix, SparseMatrix *kernel);

#endif