#!/usr/bin/env python
# encoding: utf-8

import unittest


def stringRotation(str1, str2):
    """Check str2 is a rotation of s1, useing only one call to isSubstring

    :str1: string
    :str2: string
    :returns: Boolean
    make a append another copy of str2 at the end of str2. so new string has complete
    loop of itself.
    then use isSubstring will check
    """
    if len(str1) != len(str2):
        return False
    rotating_str = str2.join(str2)
    if str1 in rotating_str:
        return True
    else:
        return False


class TestStringRotation(unittest.TestCase):

    """Unit test for roation string"""

    def test_empty_string(self):
        """Test Empty string
        """
        self.assertTrue(stringRotation("", ""))
        self.assertFalse(stringRotation("abc", ""))
        self.assertFalse(stringRotation("", "cde"))

    def test_not_rotating_string(self):
        """Test  string is false
        """
        self.assertFalse(stringRotation("ze", "chen"))
        self.assertFalse(stringRotation("chen", "ze"))

    def test_rotating_string(self):
        """Test  string is True
        """
        self.assertFalse(stringRotation("ze", "eze"))
        self.assertFalse(stringRotation("WaterBottle", "terBottleWa"))

if __name__ == '__main__':
    unittest.main()
