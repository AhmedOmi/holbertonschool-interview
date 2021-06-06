#!/usr/bin/python3
"""
The N queens puzzle is the challenge of placing
N non-attacking queens on an N×N chessboard.
Write a program that solves the N queens problem.
"""

import sys


def printSolution(chessboard, n):
    """print the coordinates row and column for the position of
       each N queen """
    s = []
    for i in range(n):
        for j in range(n):
            if chessboard[i][j] == 1:
                s.append([i, j])
    print(s)


def isSafe(chessboard, row, col, n):
    """checking if a queen can be placed on board[row][col]
    """
    for i in range(col):
        if chessboard[row][i] == 1:
            return False
    for i, j in zip(range(row, -1, -1),
                    range(col, -1, -1)):
        if chessboard[i][j] == 1:
            return False
    for i, j in zip(range(row, n, 1),
                    range(col, -1, -1)):
        if chessboard[i][j] == 1:
            return False

    return True


def solveNQUtil(chessboard, col, n):
    """function to solve the n queen problem using Backtracking
    """
    if col == n:
        printSolution(chessboard, n)
        return True
    count = False
    for i in range(n):
        if isSafe(chessboard, i, col, n):
            chessboard[i][col] = 1
            count = solveNQUtil(chessboard, col + 1, n) or count
            chessboard[i][col] = 0
    return count


if __name__ == "__main__":
    """ main function to start app
    """
    if not len(sys.argv) == 2:
        print("Usage: nqueens N")
        sys.exit(1)

    if not (sys.argv[1]).isdigit():
        print("N must be a number")
        sys.exit(1)

    n = int(sys.argv[1])
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    chessboard = [[0 for i in range(n)] for j in range(n)]
    solveNQUtil(chessboard, 0, n)
