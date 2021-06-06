#!/usr/bin/python3
"""
write a method that calculates the fewest number of operations
needed to result in exactly n H characters in the file.
"""
from math import sqrt


def minOperations(n):
    """
    minOperation
    :param n: int
    :return: int
    """
    if n < 2:
        return 0
    else:
        for i in range(2, n + 1):
            if n % i == 0:
                return minOperations(n // i) + i
