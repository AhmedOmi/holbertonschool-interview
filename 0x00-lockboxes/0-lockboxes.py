#!/usr/bin/python3
"""function to test can be open"""


def canUnlockAll(boxes):
    """
    test boxes
    """
    if type(boxes) != list:
        return False
    if len(boxes) == 0:
        return False
    keys = [0]
    for k in keys:
        for value in boxes[k]:
            if value not in keys:
                if value != k and value < len(boxes) and value != 0:
                    keys.append(value)
    if len(keys) == len(boxes):
        return True
    else:
        return False
