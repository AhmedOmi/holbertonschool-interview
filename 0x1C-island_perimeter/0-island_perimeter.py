#!/usr/bin/python3
"""
the island described in grid
"""


def island_perimeter(grid):
    """
    a function that returns the perimeter of the island described in grid
    """
    p = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                if i - 1 < 0 or grid[i - 1][j] == 0:
                    p += 1
                if i + 1 >= len(grid) or grid[i + 1][j] == 0:
                    p += 1
                if j - 1 < 0 or grid[i][j - 1] == 0:
                    p += 1
                if j + 1 >= len(grid[i]) or grid[i][j + 1] == 0:
                    p += 1
    return p
