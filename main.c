#include "SparseMatrix.h"
#include <stdio.h>
#include <stdlib.h>

void get_sum_scalar();
void multiplication();
void multiplication_per_element();
void transpose();
void swaps();
void binary();
void slice();
void convolution();

int main() {

    // ====================== TESTING THE FIRST FUNCTIONS TILL THE MULTIPLICATION BY A SCALAR ======================
    printf("================= TESTING GET FUNCION, SUM AND MULTIPLICATION FOR SCALAR =================\n\n");
    get_sum_scalar();

    // ====================== TESTING MULTIPLICATION ======================
    printf("================= TESTING MULTIPLICATION =================\n\n");
    multiplication();

    // ====================== TESTING MULTIPLICATION PER ELEMENT ======================
    printf("================= TESTING MULTIPLICATION PER ELEMENT =================\n\n");
    multiplication_per_element();

    // ====================== TESTING TRANSPOSE ======================
    printf("================= TESTING TRANSPOSE =================\n\n");
    transpose();

    // ====================== TESTING SWAP ======================
    printf("================= TESTING TRANSPOSE =================\n\n");
    swaps();

    // ====================== TESTING BINARY ======================
    printf("================= TESTING BINARY =================\n\n");
    binary();

    // ====================== TESTING SLICE ======================
    printf("================= TESTING SLICE =================\n\n");
    slice();

    // ====================== TESTING CONVOLUTION ======================
    printf("================= TESTING CONVOLUTION =================\n\n");
    convolution();

    return 0;
}

void get_sum_scalar() {
    SparseMatrix *matrix = sparse_matrix_construct(5, 5);
    
    sparse_matrix_add_element(matrix, 2, 0, 0);
    sparse_matrix_add_element(matrix, 5, 0, 1);
    sparse_matrix_add_element(matrix, 3, 0, 2);
    sparse_matrix_add_element(matrix, 0, 0, 0);
    sparse_matrix_add_element(matrix, 6, 1, 1);
    sparse_matrix_add_element(matrix, 7, 1, 2);
    sparse_matrix_add_element(matrix, 8, 1, 4);
    sparse_matrix_add_element(matrix, 10, 1, 3);
    sparse_matrix_add_element(matrix, 2, 6, 0);
    
    printf("Matrix 1:\n");
    sparse_matrix_print(matrix);

    float key = 0;
    key = sparse_matrix_get(matrix, 1, 1);

    printf("Key = %.1f\n", key);

    SparseMatrix *matrix2 = sparse_matrix_construct(5, 5);
    sparse_matrix_add_element(matrix2, 2, 0, 0);
    sparse_matrix_add_element(matrix2, 3, 0, 1);
    sparse_matrix_add_element(matrix2, 21, 1, 1);
    sparse_matrix_add_element(matrix2, 9, 1, 4);
    sparse_matrix_add_element(matrix2, 5, 1, 3);

    printf("Matrix 2:\n");
    sparse_matrix_print(matrix2);

    SparseMatrix *sum = sparse_matrix_sum(matrix, matrix2);

    printf("Sum:\n");
    sparse_matrix_print(sum);

    int scalar = 3;
    SparseMatrix *matrix_scalar = sparse_matrix_scalar_multiplication(matrix, scalar);
    printf("Multiplying matrix1 by %d\n", scalar);
    sparse_matrix_print(matrix_scalar);


    sparse_matrix_destroy(matrix);
    sparse_matrix_destroy(matrix2);
    sparse_matrix_destroy(sum);
    sparse_matrix_destroy(matrix_scalar);
}

void multiplication() {
    SparseMatrix *m1 = sparse_matrix_construct(2, 3);

    sparse_matrix_add_element(m1, 4, 0, 0);
    sparse_matrix_add_element(m1, 2, 0, 1);
    sparse_matrix_add_element(m1, 1, 0, 2);
    sparse_matrix_add_element(m1, 3, 1, 0);
    sparse_matrix_add_element(m1, 6, 1, 1);
    sparse_matrix_add_element(m1, 4, 1, 2);

    printf("Matrix 1:\n");
    sparse_matrix_print(m1);

    SparseMatrix *m2 = sparse_matrix_construct(3, 2);

    sparse_matrix_add_element(m2, 1, 0, 0);
    sparse_matrix_add_element(m2, 6, 0, 1);
    sparse_matrix_add_element(m2, 2, 1, 0);
    sparse_matrix_add_element(m2, 1, 1, 1);
    sparse_matrix_add_element(m2, 4, 2, 0);
    sparse_matrix_add_element(m2, 7, 2, 1);

    printf("Matrix 2:\n");
    sparse_matrix_print(m2);

    SparseMatrix *result = sparse_matrix_multiply(m1, m2);

    printf("Result Multiplication:\n");
    sparse_matrix_print(result);

    sparse_matrix_destroy(m1);
    sparse_matrix_destroy(m2);
    sparse_matrix_destroy(result);
}

void multiplication_per_element() {
    SparseMatrix *m1 = sparse_matrix_construct(2, 2);

    sparse_matrix_add_element(m1, 2, 0, 0);
    sparse_matrix_add_element(m1, 4, 0, 1);
    sparse_matrix_add_element(m1, 5, 1, 0);
    sparse_matrix_add_element(m1, 8, 1, 1);

    printf("Matrix 1:\n");
    sparse_matrix_print(m1);

    SparseMatrix *m2 = sparse_matrix_construct(2, 2);

    sparse_matrix_add_element(m2, 5, 0, 0);
    sparse_matrix_add_element(m2, 1, 0, 1);
    sparse_matrix_add_element(m2, 3, 1, 0);
    sparse_matrix_add_element(m2, 6, 1, 1);

    printf("Matrix 2:\n");
    sparse_matrix_print(m2);

    SparseMatrix *result = sparse_matrix_per_element_multiply(m1, m2);

    printf("RESULT:\n");
    sparse_matrix_print(result);

    sparse_matrix_destroy(m1);
    sparse_matrix_destroy(m2);
    sparse_matrix_destroy(result);
}

void transpose() {
    SparseMatrix *m1 = sparse_matrix_construct(3, 2);

    sparse_matrix_add_element(m1, 1, 0, 0);
    sparse_matrix_add_element(m1, 6, 0, 1);
    sparse_matrix_add_element(m1, 1, 1, 1);
    sparse_matrix_add_element(m1, 4, 2, 0);

    printf("Matrix:\n");
    sparse_matrix_dense_print(m1);

    SparseMatrix *transpose = sparse_matrix_transpose(m1);

    printf("Matrix Transposed:\n");
    sparse_matrix_dense_print(transpose);

    sparse_matrix_destroy(m1);
    sparse_matrix_destroy(transpose);
}

void swaps() {
    SparseMatrix *m1 = sparse_matrix_construct(3, 3);

    sparse_matrix_add_element(m1, 1, 0, 0);
    sparse_matrix_add_element(m1, 6, 0, 1);
    sparse_matrix_add_element(m1, 4, 1, 1);
    sparse_matrix_add_element(m1, 8, 2, 0);
    sparse_matrix_add_element(m1, 5, 2, 2);

    printf("Matrix 1:\n");
    sparse_matrix_dense_print(m1);

    // SWAPPING ROWS

    int row_1 = 2;
    int row_2 = 1;

    SparseMatrix *swap_row = sparse_matrix_row_swap(m1, row_1, row_2);

    printf("Swapping row %d with %d:\n", row_1, row_2);
    sparse_matrix_dense_print(swap_row);

    sparse_matrix_destroy(swap_row);

    // SWAPPING COLUMNS

    int column_1 = 2;
    int column_2 = 1;

    SparseMatrix *swap_col = sparse_matrix_column_swap(m1, column_1, column_2);

    printf("Swapping column %d with %d:\n", column_1, column_2);
    sparse_matrix_dense_print(swap_col);

    sparse_matrix_destroy(m1);
    sparse_matrix_destroy(swap_col);
}

void slice() {
    SparseMatrix *m1 = sparse_matrix_construct(5, 5);

    sparse_matrix_add_element(m1, 40, 1, 0);
    sparse_matrix_add_element(m1, 30, 1, 1);
    sparse_matrix_add_element(m1, 80, 2, 0);
    sparse_matrix_add_element(m1, 100, 2, 1);
    sparse_matrix_add_element(m1, 40, 2, 2);
    sparse_matrix_add_element(m1, 60, 3, 0);
    sparse_matrix_add_element(m1, 70, 3, 1);
    sparse_matrix_add_element(m1, 50, 3, 3);
    sparse_matrix_add_element(m1, 90, 4, 0);
    sparse_matrix_add_element(m1, 80, 4, 1);
    sparse_matrix_add_element(m1, 70, 4, 3);

    printf("Matrix 1:\n");
    sparse_matrix_dense_print(m1);

    SparseMatrix *slice = sparse_matrix_slice(m1, 0, 1, 4, 2);

    printf("Slice:\n");
    sparse_matrix_dense_print(slice);

    sparse_matrix_destroy(m1);
    sparse_matrix_destroy(slice);
}

void binary() {
    SparseMatrix *m1 = sparse_matrix_construct(3, 3);

    sparse_matrix_add_element(m1, 1, 0, 0);
    sparse_matrix_add_element(m1, 6, 0, 1);
    sparse_matrix_add_element(m1, 2, 0, 2);
    sparse_matrix_add_element(m1, 4, 1, 1);
    sparse_matrix_add_element(m1, 8, 2, 0);
    sparse_matrix_add_element(m1, 5, 2, 2);

    printf("Matrix 1:\n");
    sparse_matrix_dense_print(m1);

    sparse_matrix_save_binary(m1, "sparse_matrix-binary.bin");

    SparseMatrix *m2 = sparse_matrix_read_binary("sparse_matrix-binary.bin");

    printf("Matrix 2:\n");
    sparse_matrix_print(m2);

    sparse_matrix_destroy(m1);
    sparse_matrix_destroy(m2);
}

void convolution() {
    SparseMatrix *m1 = sparse_matrix_construct(5, 4);

    sparse_matrix_add_element(m1, 0, 0, 0);
    sparse_matrix_add_element(m1, 1, 0, 3);
    sparse_matrix_add_element(m1, 0, 1, 0);
    sparse_matrix_add_element(m1, 0, 1, 1);
    sparse_matrix_add_element(m1, 1, 1, 3);
    sparse_matrix_add_element(m1, 1, 2, 0);
    sparse_matrix_add_element(m1, -1, 2, 4);
    sparse_matrix_add_element(m1, 1, 3, 1);
    sparse_matrix_add_element(m1, -1, 4, 1);
    sparse_matrix_add_element(m1, 1, 4, 3);

    printf("Matrix 1:\n");
    sparse_matrix_dense_print(m1);

    SparseMatrix *kernel = sparse_matrix_construct(3, 1);
    sparse_matrix_add_element(kernel, 1, 0, 0);
    sparse_matrix_add_element(kernel, 1, 2, 0);

    printf("Kernel:\n");
    sparse_matrix_dense_print(kernel);

    SparseMatrix *convolution = sparse_matrix_convolution(m1, kernel);
    
    printf("Convolution:\n");
    sparse_matrix_dense_print(convolution);

    sparse_matrix_destroy(m1);
    sparse_matrix_destroy(kernel);
    sparse_matrix_destroy(convolution);

}