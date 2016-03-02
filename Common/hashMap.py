#!/usr/bin/env python
# encoding: utf-8

class   hashMap(object):

    def __init__(self, size = 256):
       self.buckets = []
       self.bucket_size = size
       self.size = 0
       for i in range(0, self.bucket_size):
           self.buckets.append([])

    def hashKey(self, key):
        index = hash(key) % len(self.buckets)
        return index

    def find(self, key):
        bucket = self.buckets[self.hashKey(key)]
        for i, kv in enumerate(bucket):
            k, v = kv
            if k == key:
                return i, k, v
        return -1, key,None

    def insert(self, key, val):
        i, k, v = self.find(key)
        index = self.hashKey(key)
        bucket = self.buckets[index]
        if (v == None):
            bucket.append([key, val])
            self.size += 1
        else:
            bucket[i] = (key,val)

    def erase(self, key):
        i, k, v = self.find(key)
        index = self.hashKey(key)
        bucket = self.buckets[index]
        if (v != None):
            bucket.pop(i)
            self.size -= 1

    def printMap(self):
        for bucket in self.buckets:
            if bucket:
                for k, val in bucket:
                    print k, val

    def getSize(self):
        return self.size

    def getBucketSize(self):
        return self.bucket_size
