#!/usr/bin/env python
# encoding: utf-8

import unittest


def stringPermutation_sort(str1, str2):
    """determine, str1 is a permutation of str2
    method 1, check they have same # of chars
    method 2, check they have exactly same value after sorted. O(nlogn) based on sorting
    """

    sorted_str1 = sorted(str1)
    sorted_str2 = sorted(str2)

    if (sorted_str1 == sorted_str2):
        return True
    else:
        return False

def stringPermutation_num(str1,str2):
    if len(str1) != len(str2):
        return False
    dict1 = {}
    dict2 = {}
    for i in str1:
        val = dict1.get(i)
        if val == None:
            dict1[i] = 1
        else:
            dict1[i] = val +1
    for i in str2:
        val = dict2.get(i)
        if val == None:
            dict2[i] = 1
        else:
            dict2[i] = val +1

    if not cmp(dict1, dict2):
        return True
    else:
        return False

class TestStringPermutation(unittest.TestCase):

    def test_empty_string(self):
        self.assertEqual(stringPermutation_num("", ""), True)
        self.assertEqual(stringPermutation_sort("", ""), True)


    def test_different_len(self):
        self.assertEqual(stringPermutation_num("fsf", ""), False)
        self.assertEqual(stringPermutation_sort("abc", "ac"), False)

    def test_isPermutation_sort(self):
        self.assertEqual(stringPermutation_sort("abc", "bca"), True)
        self.assertEqual(stringPermutation_sort("baa", "aba"), True)
        self.assertEqual(stringPermutation_sort("aaa", "aaa"), True)

    def test_isPermutation_num(self):
        self.assertEqual(stringPermutation_num("abc", "bca"), True)
        self.assertEqual(stringPermutation_num("baa", "aba"), True)
        self.assertEqual(stringPermutation_num("aaa", "aaa"), True)


if __name__== '__main__':
    unittest.main()
