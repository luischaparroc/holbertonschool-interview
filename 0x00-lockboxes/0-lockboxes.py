#!/usr/bin/python3
"""Exercise to practice interview"""
from itertools import dropwhile


def canUnlockAll(boxes):
    """Checks if all boxes can be unlocked"""

    keys = {0}
    range_boxes = range(len(boxes))

    while True:
        not_found = set()

        for i in range_boxes:
            if i in keys:
                for key in dropwhile(lambda k: k in keys, boxes[i]):
                    keys.add(key)
            else:
                not_found.add(i)

        if range_boxes == not_found:
            return False

        if not not_found:
            return True

        range_boxes = not_found
