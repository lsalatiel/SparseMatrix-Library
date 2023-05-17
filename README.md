# **A Sparse Matrix Library**
## Introduction
___

A sparse matrix is a matrix that have the majority of its elements equal to zero.

Using a sparse matrix, instead of a dense matrix, saves memory because there are less non-zero elements to store. Besides, it also reduces the computing time of some operations.

In short, we use sparses matrices trying to achieve gains in performance.


## Some rules
___

This library was made based on the following statements:

1- A position in a matrix is written like: (i, j), where i = row, j = column

2- The first element of a matrix is at the position (0,0)

3- The kernel for a convolution must have odd dimensions