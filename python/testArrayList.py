#!/usr/bin/env python
# encoding: utf-8

import unittest
import arrayList

class TestArrayList(unittest.TestCase):

    def test_init(self):
        m_array = arrayList.arrayList(4)
        self.assertEqual(m_array.capacity, 4)
        self.assertEqual(m_array.size, 1)

if __name__ == "__main__":
    unittest.main()
