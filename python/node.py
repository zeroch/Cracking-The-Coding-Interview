#!/usr/bin/env python
# encoding: utf-8

import copy


class node(object):

    """Node class for List"""

    def __init__(self, data=None):
        """init constructor
        val: data
        next: node
       """
        self.val = data
        self.next = None

    def __cmp__(self, other):
        if (self is None and other is None):
            return True
        elif (self is None or other is None):
            return False
        else:
            return (cmp(self.val, other.val) and
                    cmp(self.next, other.next))

    def copy(self):
        return copy.copy(self)

    def val(self):
        return self.val

    def next(self):
        return self.next
