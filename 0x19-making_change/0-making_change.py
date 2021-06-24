#!/usr/bin/python3
"""
Given a pile of coins of different values, 
determine the fewest number of coins needed 
to meet a given amount total
"""


def makeChange(coins, total):
    """
    coins is a list of the values of the coins in your possession
    """
    if total <= 0:
        return 0
    coins.reverse()
    count = 0
    for i in coins:
        count+= total // i
        total = total % i
    if (total != 0):
        return -1
    return count
