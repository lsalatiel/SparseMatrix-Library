#include "SparseMatrix.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    // ====================== TESTING THE FIRST FUNCTIONS TILL THE MULTIPLICATION BY A SCALAR ======================


    // SparseMatrix *matrix = sparse_matrix_construct(5, 5);
    
    // sparse_matrix_add_element(matrix, 2, 0, 0);
    // sparse_matrix_add_element(matrix, 5, 0, 1);
    // sparse_matrix_add_element(matrix, 3, 0, 2);
    // sparse_matrix_add_element(matrix, 0, 0, 0);
    // sparse_matrix_add_element(matrix, 6, 1, 1);
    // sparse_matrix_add_element(matrix, 7, 1, 2);
    // sparse_matrix_add_element(matrix, 8, 1, 4);
    // sparse_matrix_add_element(matrix, 10, 1, 3);
    // sparse_matrix_add_element(matrix, 2, 6, 0);
    
    // printf("Matrix 1:\n");
    // sparse_matrix_print(matrix);

    // float key = 0;
    // key = sparse_matrix_get(matrix, 1, 1);

    // printf("Key = %.1f\n", key);

    // SparseMatrix *matrix2 = sparse_matrix_construct(5, 5);
    // sparse_matrix_add_element(matrix2, 2, 0, 0);
    // sparse_matrix_add_element(matrix2, 3, 0, 1);
    // sparse_matrix_add_element(matrix2, 21, 1, 1);
    // sparse_matrix_add_element(matrix2, 9, 1, 4);
    // sparse_matrix_add_element(matrix2, 5, 1, 3);

    // printf("Matrix 2:\n");
    // sparse_matrix_print(matrix2);

    // SparseMatrix *sum = sparse_matrix_sum(matrix, matrix2);

    // printf("Sum:\n");
    // sparse_matrix_print(sum);

    // int scalar = 3;
    // SparseMatrix *matrix_scalar = sparse_matrix_scalar_multiplication(matrix, scalar);
    // printf("Multiplying matrix1 by %d\n", scalar);
    // sparse_matrix_print(matrix_scalar);


    // sparse_matrix_destroy(matrix);
    // sparse_matrix_destroy(matrix2);
    // sparse_matrix_destroy(sum);
    // sparse_matrix_destroy(matrix_scalar);

    // ====================== TESTING MULTIPLICATION ======================

    // SparseMatrix *m1 = sparse_matrix_construct(2, 3);

    // sparse_matrix_add_element(m1, 4, 0, 0);
    // sparse_matrix_add_element(m1, 2, 0, 1);
    // sparse_matrix_add_element(m1, 1, 0, 2);
    // sparse_matrix_add_element(m1, 3, 1, 0);
    // sparse_matrix_add_element(m1, 6, 1, 1);
    // sparse_matrix_add_element(m1, 4, 1, 2);

    // printf("Matrix 1:\n");
    // sparse_matrix_print(m1);

    // SparseMatrix *m2 = sparse_matrix_construct(3, 2);

    // sparse_matrix_add_element(m2, 1, 0, 0);
    // sparse_matrix_add_element(m2, 6, 0, 1);
    // sparse_matrix_add_element(m2, 2, 1, 0);
    // sparse_matrix_add_element(m2, 1, 1, 1);
    // sparse_matrix_add_element(m2, 4, 2, 0);
    // sparse_matrix_add_element(m2, 7, 2, 1);

    // printf("Matrix 2:\n");
    // sparse_matrix_print(m2);

    // SparseMatrix *result = sparse_matrix_multiply(m1, m2);

    // printf("Result Multiplication:\n");
    // sparse_matrix_print(result);

    // sparse_matrix_destroy(m1);
    // sparse_matrix_destroy(m2);
    // sparse_matrix_destroy(result);


    // ====================== TESTING MULTIPLICATION PER ELEMENT ======================

    // SparseMatrix *m1 = sparse_matrix_construct(2, 2);

    // sparse_matrix_add_element(m1, 2, 0, 0);
    // sparse_matrix_add_element(m1, 4, 0, 1);
    // sparse_matrix_add_element(m1, 5, 1, 0);
    // sparse_matrix_add_element(m1, 8, 1, 1);

    // printf("Matrix 1:\n");
    // sparse_matrix_print(m1);

    // SparseMatrix *m2 = sparse_matrix_construct(2, 2);

    // sparse_matrix_add_element(m2, 5, 0, 0);
    // sparse_matrix_add_element(m2, 1, 0, 1);
    // sparse_matrix_add_element(m2, 3, 1, 0);
    // sparse_matrix_add_element(m2, 6, 1, 1);

    // printf("Matrix 2:\n");
    // sparse_matrix_print(m2);

    // SparseMatrix *result = sparse_matrix_per_element_multiply(m1, m2);

    // printf("RESULT:\n");
    // sparse_matrix_print(result);

    // sparse_matrix_destroy(m1);
    // sparse_matrix_destroy(m2);
    // sparse_matrix_destroy(result);


    // ====================== TESTING TRANSPOSE ======================

    // SparseMatrix *m1 = sparse_matrix_construct(3, 2);

    // sparse_matrix_add_element(m1, 1, 0, 0);
    // sparse_matrix_add_element(m1, 6, 0, 1);
    // sparse_matrix_add_element(m1, 2, 1, 0);
    // sparse_matrix_add_element(m1, 1, 1, 1);
    // sparse_matrix_add_element(m1, 4, 2, 0);
    // sparse_matrix_add_element(m1, 7, 2, 1);

    // printf("Matrix:\n");
    // sparse_matrix_standard_print(m1);

    // SparseMatrix *transpose = sparse_matrix_transpose(m1);

    // printf("Matrix Transposed:\n");
    // sparse_matrix_standard_print(transpose);

    // sparse_matrix_destroy(m1);
    // sparse_matrix_destroy(transpose);


    // ====================== TESTING SWAP ======================

    // SparseMatrix *m1 = sparse_matrix_construct(3, 3);

    // sparse_matrix_add_element(m1, 1, 0, 0);
    // sparse_matrix_add_element(m1, 6, 0, 1);
    // sparse_matrix_add_element(m1, 2, 0, 2);
    // sparse_matrix_add_element(m1, 7, 1, 0);
    // sparse_matrix_add_element(m1, 4, 1, 1);
    // sparse_matrix_add_element(m1, 9, 1, 2);
    // sparse_matrix_add_element(m1, 8, 2, 0);
    // sparse_matrix_add_element(m1, 3, 2, 1);
    // sparse_matrix_add_element(m1, 5, 2, 2);

    // printf("Matrix 1:\n");
    // sparse_matrix_standard_print(m1);

    // // SWAPPING ROWS

    // int row_1 = 2;
    // int row_2 = 1;

    // SparseMatrix *swap = sparse_matrix_row_swap(m1, row_1, row_2);

    // printf("Swapping row %d with %d:\n", row_1, row_2);

    // // SWAPPING COLUMNS

    // int column_1 = 2;
    // int column_2 = 1;

    // SparseMatrix *swap = sparse_matrix_column_swap(m1, column_1, column_2);

    // printf("Swapping column %d with %d:\n", column_1, column_2);
    // sparse_matrix_standard_print(swap);

    // sparse_matrix_destroy(m1);
    // sparse_matrix_destroy(swap);


    // ====================== TESTING BINARY ======================

    // SparseMatrix *m1 = sparse_matrix_construct(3, 3);

    // sparse_matrix_add_element(m1, 1, 0, 0);
    // sparse_matrix_add_element(m1, 6, 0, 1);
    // sparse_matrix_add_element(m1, 2, 0, 2);
    // //sparse_matrix_add_element(m1, 7, 1, 0);
    // sparse_matrix_add_element(m1, 4, 1, 1);
    // //sparse_matrix_add_element(m1, 9, 1, 2);
    // sparse_matrix_add_element(m1, 8, 2, 0);
    // sparse_matrix_add_element(m1, 3, 2, 1);
    // sparse_matrix_add_element(m1, 5, 2, 2);

    // printf("Matrix 1:\n");
    // sparse_matrix_standard_print(m1);

    // sparse_matrix_save_binary(m1, "sparse_matrix-binary.bin");

    // SparseMatrix *m2 = sparse_matrix_read_binary("sparse_matrix-binary.bin");

    // printf("Matrix 2:\n");
    // sparse_matrix_print(m2);

    // sparse_matrix_destroy(m1);
    // sparse_matrix_destroy(m2);

    
    // ====================== TESTING SLICE ======================

    SparseMatrix *m1 = sparse_matrix_construct(5, 5);

    sparse_matrix_add_element(m1, 10, 0, 0);
    //sparse_matrix_add_element(m1, 6, 0, 1);
    sparse_matrix_add_element(m1, 20, 0, 2);
    //sparse_matrix_add_element(m1, 2, 0, 3);
    sparse_matrix_add_element(m1, 10, 0, 4);
    sparse_matrix_add_element(m1, 40, 1, 0);
    sparse_matrix_add_element(m1, 30, 1, 1);
    //sparse_matrix_add_element(m1, 9, 1, 2);
    sparse_matrix_add_element(m1, 50, 1, 3);
    //sparse_matrix_add_element(m1, 9, 1, 4);
    sparse_matrix_add_element(m1, 80, 2, 0);
    sparse_matrix_add_element(m1, 100, 2, 1);
    sparse_matrix_add_element(m1, 40, 2, 2);
    //sparse_matrix_add_element(m1, 5, 2, 3);
    sparse_matrix_add_element(m1, 50, 2, 4);
    sparse_matrix_add_element(m1, 60, 3, 0);
    sparse_matrix_add_element(m1, 70, 3, 1);
    //sparse_matrix_add_element(m1, 50, 3, 2);
    sparse_matrix_add_element(m1, 50, 3, 3);
    //sparse_matrix_add_element(m1, 50, 3, 4);
    sparse_matrix_add_element(m1, 90, 4, 0);
    sparse_matrix_add_element(m1, 80, 4, 1);
    //sparse_matrix_add_element(m1, 50, 4, 2);
    sparse_matrix_add_element(m1, 70, 4, 3);
    //sparse_matrix_add_element(m1, 50, 4, 4);

    printf("Matrix 1:\n");
    sparse_matrix_standard_print(m1);

    SparseMatrix *slice = sparse_matrix_slice(m1, 0, 1, 4, 2);

    printf("Slice:\n");
    sparse_matrix_standard_print(slice);

    sparse_matrix_destroy(m1);
    sparse_matrix_destroy(slice);

    return 0;
}