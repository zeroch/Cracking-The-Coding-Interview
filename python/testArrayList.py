#!/usr/bin/env python
# encoding: utf-8

import unittest
import arrayList

class TestArrayList(unittest.TestCase):

    def test_init(self):
        m_array = arrayList.arrayList(4)
        self.assertEqual(m_array.get_capacity(), 4)
        self.assertEqual(m_array.get_size(), 0)

    def test_insert(self):
        m_array = arrayList.arrayList(2)
        m_array.add(2)
        m_array.add(1)
        self.assertEqual(m_array.get_size(), 2)
        self.assertEqual(m_array.indexOf(0), 2)
        self.assertEqual(m_array.indexOf(1), 1)

    def test_resize(self):
        m_array = arrayList.arrayList(2)
        m_array.add(2)
        self.assertEqual(m_array.get_capacity(), 2)
        m_array.add(1)
        self.assertEqual(m_array.get_capacity(), 2)
        m_array.add(1)
        self.assertEqual(m_array.get_capacity(), 4)
        self.assertEqual(m_array.get_size(), 3)

    def test_remove(self):
        m_array = arrayList.arrayList(2)
        m_array.add(1)
        self.assertEqual(m_array.get_capacity(), 2)
        m_array.add(2)
        m_array.add(3)
        self.assertEqual(m_array.get_size(), 3)
        m_array.delete(1)
        self.assertEqual(m_array.get_capacity(), 4)
        self.assertEqual(m_array.get_size(), 2)
        self.assertEqual(m_array.indexOf(2), None)

    def test_set(self):
        m_array = arrayList.arrayList(2)
        m_array.add(2)
        m_array.add(2)
        m_array.add(2)
        self.assertEqual(m_array.indexOf(1), 2)
        m_array.set(1, 30)
        self.assertEqual(m_array.indexOf(1), 30)

if __name__ == "__main__":
    unittest.main()
