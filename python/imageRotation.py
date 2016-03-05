#!/usr/bin/env python
# encoding: utf-8

import unittest


def imageRotation(img):
    """To rotate image by 90 degree,

    :img: a list of list, size outside and inside should match
    :returns: rotated image
    idea: to make a 90 degree rotation, we can performance as
    a vertical symatric swap and, / symatric swap
    Note: use img[i], img[j] = img[j], img[i] to make swap.
    Good to know

    """

    size_M = len(img)
    size_N = len(img[0])
    if size_N == 0:
        return img
    # make a | swap, so it is img[i][j], img[size_M-1-i][j] =
    #                           img[size_M-1-i][j], img[i][j]
    for i in range(0, size_M):
        for j in range(0, size_M /2):
            print img[i][j], img[i][size_M -1 -j]
            img[i][j], img[i][size_M -1 -j] = img[i][size_M -1 - j], img[i][j]
    print img
    # make a / swap  img[i][j] , img[size_M -1 -j][size_M -1 -i]
    n = size_M /2 +1
    print "i limits: ", size_M /2
    for i in range(0, size_M):
        print "current i, n : ", i, n

        j = 0
        while (j < n):
            print img[i][j], img[size_M -1 -j][size_M -1 -i]
            img[i][j], img[size_M -1 -j][size_M -1 -i] = img[size_M -1 -j][size_M -1 -i], img[i][j]
            j += 1
        n -= 1
        print "next n : ", n, "current i: ", i

    return img


class TestImageRotation(unittest.TestCase):

    """Test Image Rotation Function, rotate 90 degree of a image
    which represented by a NxN matrix, where each pixel in the image is 4 bytes"""

    def test_empty_matrix(self):
        """Test the matrix is empty say, 0x0
        :returns: TODO

        """
        test_matrix = [[]]  # case that None inside the list
        ret_matrix = [[]]
        self.assertEqual(imageRotation(test_matrix), ret_matrix)

    def test_regular_matrix(self):
        """I don't see other edge case for this question
        so test the regular directly
        :returns: TODO
        size of 2, and size of 4
        """
        test_matrix = [[1, 2], [3, 4]]
        ret_matrix = [[3, 1], [4, 2]]
        self.assertEqual(imageRotation(test_matrix), ret_matrix)

        test_matrix = [[1, 2, 3, 4], [5, 6, 7, 8],
                       [9, 10, 11, 12], [13, 14, 15, 16]]
        ret_matrix = [[13, 9, 5, 1], [14, 10, 6, 2],
                      [15, 11, 7, 3], [16, 12, 8, 4]]
        self.assertEqual(imageRotation(test_matrix), ret_matrix)

    def test_odd_size_matrix(self):
        """Test when matrix size is odd, like 3
        :returns: TODO
         size of 3, and 5

        """
        test_matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
        ret_matrix = [[7, 4, 1], [8, 5, 2], [9, 6, 3]]
        self.assertEqual(imageRotation(test_matrix), ret_matrix)

        test_matrix = [[1, 2, 3, 4, 5], [6, 7, 8, 9, 10],
                       [11, 12, 13, 14, 15], [16, 17, 18, 19, 20],
                       [21, 22, 23, 24, 25]]
        ret_matrix = [[21, 16, 11, 6, 1], [22, 17, 12, 7, 2],
                      [23, 18, 13, 8, 3], [24, 19, 14, 9, 4],
                      [25, 20, 15, 10, 5]]
        self.assertEqual(imageRotation(test_matrix), ret_matrix)


if __name__ == "__main__":
    unittest.main()
