#!/usr/bin/python3
""" Prime Game """


def isWinner(x, nums):
    """iswinner function"""
    if not nums or x < 1:
        return None

    mn = max(nums)
    arr = [True for _ in range(max(mn + 1, 2))]
    for i in range(2, int(pow(mn, 0.5)) + 1):
        if not arr[i]:
            continue
        for j in range(i*i, mn + 1, i):
            arr[j] = False

    arr[0] = arr[1] = False
    c = 0
    for i in range(len(arr)):
        if arr[i]:
            c += 1
        arr[i] = c

    p1 = 0
    for mn in nums:
        p1 += arr[mn] % 2 == 1
    if p1 * 2 == len(nums):
        return None
    if p1 * 2 > len(nums):
        return "Maria"
    return "Ben"
