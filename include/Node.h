#ifndef _NODE_H_
#define _NODE_H_

typedef float data_type;

typedef struct Node {
    data_type value;
    int row;
    int column;
    struct Node *row_next; // next node in the row
    struct Node *column_next; // next node in the column
} Node;

/**
 * @brief allocates space for a node structure
 * Complexity: O(1) - constant complexity
 * 
 * @param row row of the node in a matrix
 * @param column column of the node in a matrix
 * @param value value of the node in a matrix
 * @param row_next a node structure pointer that points to the next node in the row
 * @param column_next a node structure pointer that points to the next node in the column
 * @return Node* returns a node structure
 */
Node *node_construct(int row, int column, data_type value, Node *row_next, Node *column_next);

/**
 * @brief frees memory for a node structure
 * Complexity: O(1) - constant complexity
 * 
 * @param n a node structure
 */
void node_destroy(Node *n);

#endif