#!/usr/bin/env python
# encoding: utf-8

class arrayList(object):
    def __init__(self, size):
        self.capacity = size
        self.size = 0
        self.array = []

    def resize(self):
        newArray = []
        newCap = self.capacity *2;
        for i in self.capacity:
            newArray[i] = self.array[i]
        self.array = newArray

    def capacity(self):
        return self.capacity

    def size(self):
        return self.size

    def isEmpty(self):
        if ( self.size == 0):
            return True
        else:
            return False

    def add(self,data):

        if ( size >= capacity):
            self.resize()

        self.size += 1
        self.array[size] = data

    def set(self,index,data):
        if ( index < 0):
            return
        if ( self.size >= self.capacity or index > self.capacity ):
            self.resize()

        if (index <= self.size):
            # copy subset
            for i in reversed(range(index, self.size)):
                self.array[i+1] = self.array[i]
        self.array[index] = data
        self.size += 1

    def delete(self, index):
        if ( index >= 0 or index <= size):
            for i in range(index, self.size):
                self.array[i] = self.array[i+1]
            self.size -= 1

    def indexOf(self, index):
        return self.array[index]
