#!/usr/bin/env python
# encoding: utf-8

import node
import unittest


class TestNode(unittest.TestCase):

    """Test Basic Node type"""

    def testInit(self):
        """test Initial node

        """
        m_node = node.node()
        self.assertEqual(m_node.val, None)
        self.assertEqual(m_node.next, None)

        m_node = node.node(2)
        self.assertEqual(m_node.val, 2)
        self.assertEqual(m_node.next, None)

        m_node = node.node("zechen")
        self.assertEqual(m_node.val, "zechen")
        self.assertEqual(m_node.next, None)

    def testNodeCopy(self):
        """test copy function

        """
        m_node = node.node("zechen")
        n_node = m_node.copy()
        self.assertEqual(n_node.val, "zechen")
        self.assertEqual(n_node.next, None)

    def testNodeSetVal(self):
        """TODO: Docstring for testNodeSetVal.
        """
        m_node = node.node("zechen")
        m_node.val = "chen"
        self.assertEqual(m_node.val, "chen")
        self.assertEqual(m_node.next, None)

    def testNodeSetNext(self):
        """TODO: Docstring for testNodeSetVal.
        """
        m_node = node.node("zechen")
        n_node = node.node("testing")

        m_node.next = n_node
        self.assertEqual(n_node.val, "testing")
        self.assertEqual(n_node.next, None)
        self.assertEqual(m_node.val, "zechen")
        self.assertEqual(m_node.next, n_node)
        self.assertEqual(m_node.next.val, "testing")

if __name__ == "__main__":
    unittest.main()
