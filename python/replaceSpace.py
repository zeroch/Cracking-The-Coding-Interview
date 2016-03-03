#!/usr/bin/env python
# encoding: utf-8

import unittest


def replaceSpace(str, size):
    """TODO: Docstring for replaceSpace.

    :str: a string may contain space and extra space and the end
            enough space will be provided for replacing
    :returns: a str after replaced
    [x] idea: calculate how many space will be added, and last char in the string
    in place copy reversely
    time: 2*O(n)
    the idea above is not going to work.
    Note: In python, string is immuatble, You can't do in place operation.
    return a copy a string. Time: O(n)
    """
    if (size <= 0):
        return str
    afterReplaceStr = []
    i = 0
    space_count = 0
    while i < size:
        if (str[i] != ' '):
            afterReplaceStr.append(str[i])
        else:
            afterReplaceStr.append("%20")
            space_count += 2
        i += 1

    """padding empty space"""
    i +=space_count
    all_len = len(str)
    while(i < all_len):
        afterReplaceStr.append(" ")
        i +=1
    ret_str = "".join(afterReplaceStr)
    return ret_str


class TestReplaceString(unittest.TestCase):

    """Docstring for TestReplaceString. """

    def test_empty_string(self):
        """TODO: Docstring for test_empty_string.
        """
        test_str = ""
        len = 0
        dst_str = ""
        self.assertEqual(replaceSpace(test_str, len), dst_str)

        test_str = "       "
        len = 0
        dst_str = "       "
        self.assertEqual(replaceSpace(test_str, len), dst_str)

    def test_only_empty_at_end(self):
        """TODO: Docstring for test_only_empty_at_end.
        """
        test_str = "zechen     "
        len = 6
        dst_str = "zechen     "
        self.assertEqual(replaceSpace(test_str, len), dst_str)

    def test_only_empty_at_front(self):
        """TODO: Docstring for test_only_empty_at_front.
        """
        test_str = " zechen       "
        size = 7
        dst_str = "%20zechen     "

        self.assertEqual(replaceSpace(test_str, size), dst_str)

    def test_regular_string(self):
        """TODO: Docstring for test_regular_strin.
        """
        test_str = "this is ze chen           "
        size = 15
        dst_str = "this%20is%20ze%20chen     "

        self.assertEqual(replaceSpace(test_str, size), dst_str)


if __name__ == '__main__':
    unittest.main()
