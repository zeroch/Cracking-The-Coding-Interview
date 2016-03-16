#!/usr/bin/env python
# encoding: utf-8

import linkedList as ll
import unittest
import node as node


class TestLinkedList(unittest.TestCase):

    """unit test for linked list"""
    test_list = ll.LinkedList()

    def test_init(self):
        """Init a linked list with null root

        """

    def test_append(self):
        """Test append node behind link list
        :returns: TODO

        """

        node1 = node.node(1)
        self.test_list.append(node1)
        node2 = node.node(2)
        self.test_list.append(node2)

        self.assertEqual(node1.next, node2)

if __name__ == "__main__":
    unittest.main()


