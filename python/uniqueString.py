#!/usr/bin/env python
# encoding: utf-8
import unittest


def uniqueString(str):
    """determin a string has all unique characters,
    this is use another data stucture
    :str: a string
    :returns: True if all characters are unique
              False if there is duplicate character

    """
    dict = []
    for c in str:
        if c in dict:
            return False
        else:
            dict.append(c)

    return True


def uniqueString_sort(str):
    copy_str = sorted(str)
    for i in range(0, len(str) -2):
        if (copy_str[i] == copy_str[i +1]):
            return False
    return True


class TestUniqueString(unittest.TestCase):

    """Docstring for TestUniqueString. """
    def test_emtpy(self):
        """
        test emtpy string, return true
        """
        self.assertEqual(uniqueString_sort(""), True)

    def test_unique(self):
        """TODO: Docstring for test unique string
        """
        self.assertEqual(uniqueString_sort("abcdefg"), True)
        self.assertEqual(uniqueString_sort("&^scd"), True)

    def test_noUnique(self):
        self.assertEqual(uniqueString_sort("abacefg"), False)
        self.assertEqual(uniqueString_sort("affdsfdj"), False)

    def test_Upper_Lower_char(self):
        """TODO: Docstring for test_Upper_Lower_char.
        """
        self.assertEqual(uniqueString_sort("abcABC"), True)
        self.assertEqual(uniqueString_sort("bcdBCD"), True)


if __name__ == '__main__':
    unittest.main()
