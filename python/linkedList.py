#!/usr/bin/env python
# encoding: utf-8

import copy
import node


class LinkedList(object):

    """basic data structor single linked list
    a list need
    head: node
    tail: node

    methods:
    append(node): insert a node at the end
    insert(prev, cur): insert a node at the back of prev, if prev exist
    find(val): find val in the list, return the node of this value
    delete(cur): find a node in the list and delete
    """


    def __init__(self, root=None):
        """ Init linked list

        """
        self.head = root
        self.tail = root

    def root(self):
        return self.head

    def append(self, cur_node):
        """insert a node at the end

        :cur_node: TODO
        :returns: TODO

        """
        if self.head == None:
            self.head = cur_node
            self.tail = cur_node
        else:
            self.tail.next = cur_node
            self.tail = cur_node

    def find(self, value):
        """find value in the list, return the node of this value

        :value: the value searching
        :returns: node contain val value

        """
        m_node = self.head
        while m_node != None:
            if m_node.val == value:
                return m_node
            else:
                m_node = m_node.next

        return None

    def insert(self, prev, cur):
        """insert a node at the back of prev, if prev exist

        :prev: prev node
        :cur: node list will insert
        :returns: No return

        """
        m_node =self.find(prev.val)

        if m_node != None:
            return
        else:
            cur.next = m_node.next
            m_node.next = cur
        if m_node == self.tail:
            self.tail = cur


    def delete(self, cur):
        """Find a node in the list, if node is exist, remove it
        to delete a node, we need the node before it. so we cant use
        find function
        :cur: TODO
        :returns: TODO

        """

        m_node = self.head
        # check head
        if m_node == cur:
            self.head = None
            self.tail = None

        while m_node.next != None:
            if m_node.next == cur:
                m_node.next = cur.next
                break


