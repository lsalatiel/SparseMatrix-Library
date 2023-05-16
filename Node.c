#include "Node.h"
#include <stdio.h>
#include <stdlib.h>

Node *node_construct(int row, int column, data_type value, Node *row_next, Node *column_next) {
    Node *n = malloc(sizeof(Node));

    n->row = row;
    n->column = column;
    n->value = value;
    n->row_next = row_next;
    n->column_next = column_next;

    return n;
}

void node_destroy(Node *n) {
    free(n);
}