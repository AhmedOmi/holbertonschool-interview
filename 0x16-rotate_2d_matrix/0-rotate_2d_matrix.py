#!/usr/bin/python3
"""
Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    '''
    Given an n x n 2D matrix, rotate it 90 degrees clockwise
    '''

    n = len(matrix)
    clone = []
    for i in range(n):
        sublist = []
        for j in range(n):
            sublist.append(matrix[i][j])
        clone.append(sublist)

    for i in range(n):
        for j in range(n):
            matrix[i][j] = clone[n - j - 1][i]
