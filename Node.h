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

Node *node_construct(int row, int column, data_type value, Node *row_next, Node *column_next);

void node_destroy(Node *n);

#endif