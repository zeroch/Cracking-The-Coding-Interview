#!/usr/bin/env python
# encoding: utf-8

class arrayList(object):
    def __init__(self, size):
        self.capacity = size
        self.size = 0
        self.array = []
        for i in range(size):
            self.array.append(None)


    def resize(self):
        newCap = 2* self.capacity
        newArray = []
        for i in range(0, self.capacity):
            newArray.append(self.array[i])
        for i in range(self.capacity, newCap):
            newArray.append(None)
        self.array = newArray
        self.capacity = newCap

    def get_capacity(self):
        return self.capacity

    def get_size(self):
        return self.size

    def isEmpty(self):
        if ( self.size == 0):
            return True
        else:
            return False

    def add(self,data):

        if ( self.size >= self.capacity):
            self.resize()
        self.array[self.size] = data
        self.size += 1

    def set(self,index,data):
        if ( index < 0):
            return
        elif(index > self.capacity):
            return
        elif ( self.size == self.capacity):
            self.resize()

        if (index <= self.size -1):
            # copy subset
            for i in reversed(range(index, self.size-1)):
                self.array[i+1] = self.array[i]
        self.array[index] = data
        self.size += 1

    def delete(self, index):
        if ( index == self.size -1):
            self.array.remove(index)

        if ( index >= 0 and index < self.size -1):
            for i in range(index, self.size -1):
                self.array[i] = self.array[i+1]
        self.size -= 1
        self.array[self.size] = None

    def indexOf(self, index):
        return self.array[index]
