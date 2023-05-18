#include "SparseMatrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct SparseMatrix{
    Node **row_heads;
    int row_size;
    Node **column_heads;
    int column_size;
};

SparseMatrix *sparse_matrix_construct(int row, int column) {
    SparseMatrix *matrix = malloc(sizeof(SparseMatrix));
    
    matrix->row_size = row;
    matrix->column_size = column;

    matrix->row_heads = malloc(matrix->row_size * sizeof(Node));
    matrix->column_heads = malloc(matrix->column_size * sizeof(Node));

    for(int i = 0; i < matrix->row_size; i++) {
        matrix->row_heads[i] = NULL;
    }

    for(int i = 0; i < matrix->column_size; i++) {
        matrix->column_heads[i] = NULL;
    }

    return matrix;
}

void _node_destroy_recursive(Node *n) {
    if(n == NULL) return;

    _node_destroy_recursive(n->row_next); // destroys the nodes from left to right
    node_destroy(n);
}

void sparse_matrix_destroy(SparseMatrix *matrix) {
    if(matrix == NULL) return;

    for(int i = 0; i < matrix->row_size; i++) {
        if(matrix->row_heads[i] != NULL) {
            _node_destroy_recursive(matrix->row_heads[i]); // destroys the node from top to bottom
            
            // non-recursive function

            // Node *current = matrix->row_heads[i];
            // Node *next;
            // while(current != NULL) {
            //     next = current->row_next;
            //     free(current);
            //     current = next;
            // }
        }
    }

    free(matrix->row_heads);
    free(matrix->column_heads);
    
    free(matrix);
}

bool _is_valid_matrix_dimensions(int row, int column, int row_size, int column_size) {
    if(row >= row_size || row < 0 || column >= column_size || column < 0) {
        printf("Position (%d,%d) not compatible with matrix dimensions\n", row, column);
        return false;
    }

    return true;
}

/**
 * @brief adds an element to the row linked list
 * Complexity: O(n), n = number of rows
 * 
 * @param matrix a sparse matrix structure
 * @param value the value to be added
 * @param row 
 * @param column 
 * @param n a node created from the value. It can be NULL if the value is 0
 */
void _matrix_add_element_row(SparseMatrix *matrix, int value, int row, int column, Node *n) {
    Node *current = matrix->row_heads[row];
    Node *prev = NULL;

    while(current != NULL) {
        if(current->column > column) {
            if(value == 0)
                return;
            else if(prev == NULL) {
                matrix->row_heads[row] = n;
                n->row_next = current;
            }
            else {
                prev->row_next = n;
                n->row_next = current;
            }
            return;
        }
        else if(current->column == column) {
            if(value == 0) {
                if(prev == NULL)
                    matrix->row_heads[row] = current->row_next;
                else
                    prev->row_next = current->row_next;
            }
            else
                current->value = value;
            return;
        }

        prev = current;
        current = current->row_next;
    }

    if(value != 0)
        prev->row_next = n;
}


/**
 * @brief adds an element to the column linked list
 * Complexity: O(m), m = number of columns
 * 
 * @param matrix a sparse matrix structure
 * @param value the value to be added
 * @param row 
 * @param column 
 * @param n a node created from the value. It can be NULL if the value is 0
 */
void _matrix_add_element_column(SparseMatrix *matrix, int value, int row, int column, Node *n) {
    Node *current = matrix->column_heads[column];
    Node *prev = NULL;

    while(current != NULL) {
        if(current->row > row) {
            if(value == 0)
                return;
            else if(prev == NULL) {
                matrix->column_heads[column] = n;
                n->column_next = current;
            }
            else {
                prev->column_next = n;
                n->column_next = current;
            }
            return;
        }
        else if(current->row == row) {
            if(value == 0) {
                if(prev == NULL) {
                    matrix->column_heads[column] = current->column_next;
                    node_destroy(current);
                }
                else
                    prev->column_next = current->column_next;
            }
            else {
                current->value = value;
                node_destroy(n);
            }
            return;
        }

        prev = current;
        current = current->column_next;
    }

    if(value != 0)
        prev->column_next = n;
}

void sparse_matrix_add_element(SparseMatrix *matrix, data_type value, int row, int column) {
    if(matrix == NULL) {
        printf("Error: matrix is NULL\n");
        return;
    }

    if(!_is_valid_matrix_dimensions(row, column, matrix->row_size, matrix->column_size)) return;

    Node* n = NULL;

    if(value != 0) {
        n = node_construct(row, column, value, NULL, NULL);
    }
    // inserting the node into the row linked list
    if(matrix->row_heads[row] == NULL && value != 0)
        matrix->row_heads[row] = n;
    else
        _matrix_add_element_row(matrix, value, row, column, n);

    // inserting the node into the column linked list
    if(matrix->column_heads[column] == NULL && value != 0)
        matrix->column_heads[column] = n;
    else
        _matrix_add_element_column(matrix, value, row, column, n);
}

void _print_node_recursive(Node *n) {
    if(n == NULL) return;

    printf("(%d, %d) = %.2f\n", n->row, n->column, n->value);
    _print_node_recursive(n->row_next);
}

void sparse_matrix_print(SparseMatrix* matrix) {
    if(matrix == NULL) {
        printf("Error: matrix is NULL\n");
        return;
    }

    for(int i = 0; i < matrix->row_size; i++) {
        if(matrix->row_heads[i] != NULL) {
            //_print_node_recursive(matrix->row_heads[i]); // recursive function
            Node* current = matrix->row_heads[i];

            while(current != NULL) {
                printf("(%d, %d) = %.2f\n", current->row, current->column, current->value);
                current = current->row_next;
            }
        }
    }
}

void sparse_matrix_dense_print(SparseMatrix* matrix) {
    if(matrix == NULL) {
        printf("Error: matrix is NULL\n");
        return;
    }

    for(int i = 0; i < matrix->row_size; i++) {
        Node* current = matrix->row_heads[i];

        for(int j = 0; j < matrix->column_size; j++) {
            if(current == NULL) {
                printf("0.00 ");
                continue;
            }
            if(current->column == j) {
                printf("%.2f ", current->value);
                current = current->row_next;
            }
            else
                printf("0.00 ");
        }
        printf("\n");
    }
}

data_type sparse_matrix_get(SparseMatrix *matrix, int row, int column) {
    if(matrix == NULL) {
        printf("Error: matrix is NULL\n");
        return 0;
    }

    if(!_is_valid_matrix_dimensions(row, column, matrix->row_size, matrix->column_size)) {
        sparse_matrix_destroy(matrix);
        exit(1);
    }

    if(matrix->row_heads[row] == NULL) return 0;

    Node *current = matrix->row_heads[row];

    while(current != NULL) {
        if(current->column == column) {
            return current->value;
        }

        current = current->row_next;
    }

    return 0;
}

SparseMatrix *sparse_matrix_sum(SparseMatrix *matrix_1, SparseMatrix *matrix_2) {
    if(matrix_1 == NULL || matrix_2 == NULL) {
        printf("Error: matrix is NULL\n");
        return NULL;
    }
    
    if(matrix_1->row_size != matrix_2->row_size || matrix_1->column_size != matrix_2->column_size) {
        printf("In order to add matrices, they must have the same dimensions\n");
        exit(1);
    }

    SparseMatrix *matrix_sum = sparse_matrix_construct(matrix_1->row_size, matrix_1->column_size);

    for(int i = 0; i < matrix_1->row_size; i++) {
        Node *current_1 = matrix_1->row_heads[i];
        Node *current_2 = matrix_2->row_heads[i];

        while(current_1 != NULL && current_2 != NULL) {
            if(current_1->column > current_2->column) {
                current_2 = current_2->row_next;
            }
            else if(current_1->column < current_2->column) {
                current_1 = current_1->row_next;
            }
            else {
                sparse_matrix_add_element(matrix_sum, current_1->value + current_2->value, current_1->row, current_1->column);
                current_1 = current_1->row_next;
                current_2 = current_2->row_next;
            }
        }
    }

    return matrix_sum;
}

SparseMatrix *sparse_matrix_scalar_multiplication(SparseMatrix* matrix, int scalar) {
    if(matrix == NULL) {
        printf("Error: matrix is NULL\n");
        return NULL;
    }
    
    if(scalar == 0) {
        printf("Multiplying a matrix by zero turns it into a NULL matrix\n");
        return NULL;
    }
    
    SparseMatrix *matrix_result = sparse_matrix_construct(matrix->row_size, matrix->column_size);

    for(int i = 0; i < matrix->row_size; i++) {
        Node *current = matrix->row_heads[i];

        while(current != NULL) {
            sparse_matrix_add_element(matrix_result, scalar * current->value, current->row, current->column);
            current = current->row_next;
        }
    }

    return matrix_result;
}

SparseMatrix *sparse_matrix_multiply(SparseMatrix *matrix_1, SparseMatrix *matrix_2) {
    if(matrix_1 == NULL || matrix_2 == NULL) {
        printf("Error: matrix is NULL\n");
        return NULL;
    }

    if(matrix_1->column_size != matrix_2->row_size) {
        printf("Impossible to multiply. In order to multiply matrices, the number of columns of the first matrix must be equal to the number of rows of the second matrix.\n");
        return NULL;
    }

    SparseMatrix *matrix_result = sparse_matrix_construct(matrix_1->row_size, matrix_2->column_size);

    for(int i = 0; i < matrix_1->row_size; i++) {
        for(int j = 0; j < matrix_2->column_size; j++) {
            Node *current_1 = matrix_1->row_heads[i];
            Node *current_2 = matrix_2->column_heads[j];

            data_type sum = 0;

            while(current_1 != NULL && current_2 != NULL) {
                if(current_1->column < current_2->row) {
                    current_1 = current_1->column_next;
                }
                else if(current_1->column > current_2->row) {
                    current_2 = current_2->row_next;
                }
                else {
                    sum += current_1->value * current_2->value;
                    current_1 = current_1->row_next;
                    current_2 = current_2->column_next;
                }
            }
            
            sparse_matrix_add_element(matrix_result, sum, i, j);
        }
    }

    return matrix_result;
}

SparseMatrix *sparse_matrix_per_element_multiply(SparseMatrix *matrix_1, SparseMatrix *matrix_2) {
    if(matrix_1 == NULL || matrix_2 == NULL) {
        printf("Error: matrix is NULL\n");
        return NULL;
    }
    
    if(matrix_1->row_size != matrix_2->row_size || matrix_1->column_size != matrix_2->column_size) {
        printf("In order to multiply matrices element per element, they must have the same dimensions\n");
        exit(1);
    }

    SparseMatrix *result = sparse_matrix_construct(matrix_1->row_size, matrix_1->column_size);

    for(int i = 0; i < matrix_1->row_size; i++) {
        Node *current_1 = matrix_1->row_heads[i];
        Node *current_2 = matrix_2->row_heads[i];

        while(current_1 != NULL && current_2 != NULL) {
            if(current_1->column > current_2->column) {
                current_2 = current_2->row_next;
            }
            else if(current_1->column < current_2->column) {
                current_1 = current_1->row_next;
            }
            else {
                sparse_matrix_add_element(result, current_1->value * current_2->value, current_1->row, current_1->column);
                current_1 = current_1->row_next;
                current_2 = current_2->row_next;
            }
        }
    }

    return result;
}

SparseMatrix *sparse_matrix_transpose(SparseMatrix *matrix) {
    if(matrix == NULL) {
        printf("Error: matrix is NULL\n");
        return NULL;
    }

    SparseMatrix *transpose = sparse_matrix_construct(matrix->column_size, matrix->row_size);

    for(int i = 0; i < matrix->row_size; i++) {
        Node *current = matrix->row_heads[i];

        while(current != NULL) {
            sparse_matrix_add_element(transpose, current->value, current->column, current->row);

            current = current->row_next;
        }
    }

    return transpose;
}

SparseMatrix *sparse_matrix_row_swap(SparseMatrix *matrix, int row_1, int row_2) {
    if(matrix == NULL) {
        printf("Error: matrix is NULL\n");
        return NULL;
    }

    if(row_1 > matrix->row_size || row_1 < 0 || row_2 > matrix->row_size || row_2 < 0) {
        printf("Invalid rows.\n");
        return NULL;
    }

    SparseMatrix *matrix_swap = sparse_matrix_construct(matrix->row_size, matrix->column_size);

    for(int i = 0; i < matrix->row_size; i++) {
        Node *current = matrix->row_heads[i];

        while(current != NULL) {
            if(i == row_1)
                sparse_matrix_add_element(matrix_swap, current->value, row_2, current->column);
            else if(i == row_2)
                sparse_matrix_add_element(matrix_swap, current->value, row_1, current->column);
            else
                sparse_matrix_add_element(matrix_swap, current->value, current->row, current->column);
            current = current->row_next;
        }
    }

    return matrix_swap;
}

SparseMatrix *sparse_matrix_column_swap(SparseMatrix *matrix, int column_1, int column_2) {
    if(matrix == NULL) {
        printf("Error: matrix is NULL\n");
        return NULL;
    }

    if(column_1 > matrix->column_size || column_1 < 0 || column_2 > matrix->column_size || column_2 < 0) {
        printf("Invalid columns.\n");
        return NULL;
    }

    SparseMatrix *matrix_swap = sparse_matrix_construct(matrix->row_size, matrix->column_size);

    for(int i = 0; i < matrix->column_size; i++) {
        Node *current = matrix->column_heads[i];

        while(current != NULL) {
            if(i == column_1)
                sparse_matrix_add_element(matrix_swap, current->value, current->row, column_2);
            else if(i == column_2)
                sparse_matrix_add_element(matrix_swap, current->value, current->row, column_1);
            else
                sparse_matrix_add_element(matrix_swap, current->value, current->row, current->column);
            current = current->column_next;
        }
    }

    return matrix_swap;
}

void sparse_matrix_save_binary(SparseMatrix *matrix, char* file_name) {
    if(matrix == NULL) {
        printf("Error: matrix is NULL\n");
        return;
    }

    FILE *file = fopen(file_name, "wb");

    fwrite(&matrix->row_size, sizeof(int), 1, file);
    fwrite(&matrix->column_size, sizeof(int), 1, file);

    for(int i = 0; i < matrix->row_size; i++) {
        Node *current = matrix->row_heads[i];

        while(current != NULL) {
            fwrite(&current->value, sizeof(data_type), 1, file);
            fwrite(&current->row, sizeof(int), 1, file);
            fwrite(&current->column, sizeof(int), 1, file);
            current = current->row_next;
        }
    }

    fclose(file);
}

SparseMatrix *sparse_matrix_read_binary(char* file_name) {
    FILE *file = fopen(file_name, "rb");
    
    if(file == NULL) {
        printf("Error: could not open file.\n");
        return NULL;
    }

    int row_size = 0, column_size = 0;

    fread(&row_size, sizeof(int), 1, file);
    fread(&column_size, sizeof(int), 1, file);

    SparseMatrix *matrix = sparse_matrix_construct(row_size, column_size);

    for(int i = 0; i < matrix->row_size; i++) {
        for(int j = 0; j < matrix->column_size; j++) {
            data_type value = 0;
            int row = -1, column = -1;

            fread(&value, sizeof(data_type), 1, file);
            fread(&row, sizeof(int), 1, file);
            fread(&column, sizeof(int), 1, file);

            if(row == -1 || column == -1) {
                fclose(file);
                return matrix;
            }
                
            if(value != 0)
                sparse_matrix_add_element(matrix, value, row, column);
        }
    }

    fclose(file);

    return matrix;
}

SparseMatrix *sparse_matrix_slice(SparseMatrix *matrix, int row_1, int column_1, int row_2, int column_2) {
    if(matrix == NULL) {
        printf("Error: matrix is NULL\n");
        return NULL;
    }

    if(row_1 > row_2 || column_1 > column_2) {
        printf("Error: The first position must be above the second.\n");
        return NULL;
    }

    SparseMatrix *slice = sparse_matrix_construct(row_2 - row_1 + 1, column_2 - column_1 + 1);

    for(int i = row_1; i <= row_2; i++) {
        if(i < 0 || i >= matrix->row_size)
            continue;

        Node *current = matrix->row_heads[i];

        for(int j = 0; current != NULL; j++){
            if(j < 0 || j >= matrix->column_size)
                continue;
            if(current->column < column_1) {
                current = current->row_next;
                continue;
            }
            if(current->column > column_2)
                break;
            sparse_matrix_add_element(slice, current->value, i - row_1, current->column - column_1);
            current = current->row_next;
        }
    }
    
    return slice;
}

/**
 * @brief checks if the slice is not empty
 * Complexity: O(n), n = number of rows. The worst case is when all the row_heads are NULL
 * 
 * @param slice 
 * @return returns a boolean value. If the slice is empty, returns false. Otherwise, it returns true
 */
bool _is_valid_slice(SparseMatrix *slice) {
    for(int i = 0; i < slice->row_size; i++) {
        if(slice->row_heads[i] != NULL)
            return true;
    }

    return false;
}

SparseMatrix *sparse_matrix_convolution(SparseMatrix *matrix, SparseMatrix *kernel) {
    if(matrix == NULL || kernel == NULL) {
        printf("Error: matrix is NULL\n");
        return NULL;
    }

    if(kernel->row_size % 2 == 0 || kernel->column_size % 2 == 0) {
        printf("Error: Invalid kernel dimensions. The number of rows and columns must be odds\n");
        return NULL;
    }

    SparseMatrix *convolution = sparse_matrix_construct(matrix->row_size, matrix->column_size);

    for(int i = 0; i < matrix->row_size; i++) {
        for(int j = 0; j < matrix->column_size; j++) {
            int row_1 = i - kernel->row_size / 2;
            int col_1 = j - kernel->column_size / 2;
            int row_2 = i + kernel->row_size / 2;
            int col_2 = j + kernel->column_size / 2;

            SparseMatrix *slice_matrix = sparse_matrix_slice(matrix, row_1, col_1, row_2, col_2);
            if(slice_matrix == NULL) {
                sparse_matrix_destroy(slice_matrix);
                continue;
            }

            if(!_is_valid_slice(slice_matrix)) {
                sparse_matrix_destroy(slice_matrix);
                continue;
            }

            SparseMatrix *multip_matrix = sparse_matrix_per_element_multiply(slice_matrix, kernel);
            
            data_type sum = 0;

            for(int k = 0; k < multip_matrix->row_size; k++) {
                Node *current = multip_matrix->row_heads[k];

                while(current != NULL) {
                    sum += current->value;
                    current = current->row_next;
                }
            }

            sparse_matrix_add_element(convolution, sum, i, j);

            sparse_matrix_destroy(slice_matrix);
            sparse_matrix_destroy(multip_matrix);
        }
    }

    return convolution;
}