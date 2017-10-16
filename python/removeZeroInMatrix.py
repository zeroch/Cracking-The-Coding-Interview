#!/usr/bin/env python
# encoding: utf-8

import unittest


def setRow(mat, targetRow, num):
    for array in mat:
        array[targetRow] = num
    return mat


def setCol(mat, targetCol, num):
    for i in range(0, len(mat[targetCol])):
        mat[targetCol][i] = num
    return mat


def searchNum(mat, num):
    row_list = []
    col_list = []

    for i in range(0, len(mat)):
        for j in range(0, len(mat[i])):
            if mat[i][j] == num:
                if i not in row_list:
                    row_list.append(i)
                if j not in col_list:
                    col_list.append(j)

    return row_list, col_list


def removeZeroInMatrix(mat):
    """
    Input: mat, a MxN matrix
    Output:copy_mat, a MxN matrix

    Idea: search whole matrix, find zero in the matrix
    push row and col # into set of row and col so reduce
    the duplictate set zero

    Helper:
    helper function to set certain row and col in a matrix
    into the target num. we use 0 only here
    setRow(mat, targetRow, num)
    setCol(mat, targetCol, num)
    """

    setRow_Mat = mat
    setCol_Mat = mat
    row_list, col_list = searchNum(mat, 0)
    for i in row_list:
        setRow_Mat = setRow(mat, i, 0)
    for j in col_list:
        setCol_Mat = setCol(setRow_Mat, j, 0)

    return setCol_Mat


class TestRemoveZero(unittest.TestCase):

    """Unit test to test function that
    search 0 in a MxN matrix, and set it's row
    and colum to 0s
    """

    def test_empty_matrix(self):
        test_matrix = [[]]
        dst_matrix = [[]]
        self.assertEqual(removeZeroInMatrix(test_matrix), dst_matrix)

    def test_norma_matrix(self):
        test_matrix = [[1, 2, 3, 4], [2, 0, 3, 1]]
        dst_matrix = [[1, 0, 3, 4], [0, 0, 0, 0]]
        self.assertEqual(removeZeroInMatrix(test_matrix), dst_matrix)

if __name__ == "__main__":
    unittest.main()
