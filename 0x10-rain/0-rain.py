#!/usr/bin/python3
"""Rain projects"""


def low(l, r):
    """lower functions """
    if (r >= l):
        return(l)
    else:
        return(r)
    return(r)


def rain(walls):
    """rain calculator"""
    total = 0
    lac = 0
    for i in range(1, len(walls) - 1):
        left = walls[i]
        right = walls[i]
        for l in range(0, i):
            if (walls[l] > left):
                left = walls[l]
        for r in range(i + 1, len(walls)):
            if (walls[r] > right):
                right = walls[r]
        lac = low(left, right) - walls[i]
        total += lac
    return(total)
