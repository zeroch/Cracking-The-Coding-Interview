#!/usr/bin/env python
# encoding: utf-8

import hashMap


def testHashMap():
    testHashMapInit()
    #testHashMapInsert()
    testHashMapErase()

def testHashMapInit():
    m_map = hashMap.hashMap()
    print m_map.getBucketSize()
    print m_map.getSize()
    m_map2 = hashMap.hashMap(126)
    print m_map2.getBucketSize()
    print m_map2.getSize()

def testHashMapInsert():
    m_map = hashMap.hashMap()
    for i in range(0, 299):
        m_map.insert(i, 2*i)
    m_map.printMap()
    print m_map.getBucketSize()
    print m_map.getSize()

def testHashMapErase():
    m_map = hashMap.hashMap()
    m_map.insert("ze", "pasa")
    m_map.insert("t", "ms")
    m_map.printMap()
    m_map.erase("ze")
    m_map.printMap()


if __name__ == "__main__":
    testHashMap()
