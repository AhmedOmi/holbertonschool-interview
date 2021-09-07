#!/usr/bin/python3
"""
pascale triangle - function
"""


def pascal_triangle(n):
    """
    pascal triangel return triangle
    """
    t = [[0 for j in range(1, i + 2)] for i in range(n)]
    for i in range(len(t)):
        for j in range(len(t[i])):
            if i == 0 or j == 0 or j == i:
                t[i][j] = 1
            else:
                t[i][j] = t[i - 1][j] + t[i - 1][j - 1]
    return t
