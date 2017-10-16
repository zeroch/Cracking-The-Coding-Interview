#!/usr/bin/env python
# encoding: utf-8

import unittest


def compressString(string):
    """
    Compress input string, by counting # of continue chars
    if compressed string has longer than str, return str

    :str: a string
    :returns: compressed string

    """
    if string == "":
        return string
    origin_str = string
    origin_len = len(string)
    compres_str = []
    char_count = 0
    slow_char = string[0]
    for fast_char in string:
        if fast_char == slow_char:
            char_count += 1
        else:
            compres_str.append(slow_char)
            compres_str.append(str(char_count))
            char_count = 1
            slow_char = fast_char
    # handle last char
    compres_str.append(slow_char)
    compres_str.append(str(char_count))

    ret_str = "".join(compres_str)
    if origin_len < len(ret_str):
        return origin_str
    else:
        return ret_str


class TestCompressString(unittest.TestCase):

    """Test Compress String Function"""

    def test_empty_string(self):
        self.assertEqual(compressString(""), "")

    def test_correct_string(self):
        test_str = "aaaabbbbccd"
        dst_str = "a4b4c2d1"
        self.assertEqual(compressString(test_str), dst_str)

    def test_string_shorter_than_compression(self):
        test_str = "abcdefg"
        dst_str = "abcdefg"
        self.assertEqual(compressString(test_str), dst_str)

    def test_string_first_char_issue(self):
        test_str = "abbcccccdd"
        dst_str = "a1b2c5d2"
        self.assertEqual(compressString(test_str), dst_str)

    def test_string_last_char_issue(self):
        test_str = "aabbccdddfffg"
        dst_str = "a2b2c2d3f3g1"
        self.assertEqual(compressString(test_str), dst_str)

    def test_only_one_char(self):
        test_str = "aa"
        dst_str = "a2"
        self.assertEqual(compressString(test_str), dst_str)
        test_str = "a"
        dst_str = "a"
        self.assertEqual(compressString(test_str), dst_str)

if __name__ == '__main__':
    unittest.main()
