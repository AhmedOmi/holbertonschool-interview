#!/usr/bin/python3
""" Module to determine if a data set represents a valid UTF-8 encoding"""


def validUTF8(data):
    """
    A character in UTF-8 can be 1 to 4 bytes long
    The data set can contain multiple characters
    The data will be represented by a list of integers
    Return: True if data is a valid UTF-8 encoding, else return False
    """
    counter = 0
    bins = [bin(b).replace('0b', '').rjust(8, '0') for b in data]
    for b in bins:
        if counter != 0:
            counter -= 1
            if b[:2] != '10':
                return False
        elif b[0] == '1':
            counter = len(b.split('0')[0]) - 1
    return True