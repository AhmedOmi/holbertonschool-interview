#!/usr/bin/python3
"""
write a method that calculates the fewest number of operations
needed to result in exactly n H characters in the file.
"""
from math import sqrt


def minOperations(n):
    x = 0
    if n <= 1:
        return 0
    for i in range(2, int(sqrt(n) + 1)):
        while n % i == 0:
            x += i
            n /= i
    return x
