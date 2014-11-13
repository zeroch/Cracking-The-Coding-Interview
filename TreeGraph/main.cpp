#include "BTree.h"

int main(int argc, char const *argv[])
{


	// int size = 9;
	// int pre_order[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	// int in_order[9]  = {4, 3, 5, 2, 6, 1, 7, 8, 9};

	int size = 9;
	int pre_order[7] = {1, 2, 3, 4, 5, 6, 7};
	int in_order[7]  = {3, 2, 4, 1, 6, 5, 7};

	BTree m_tree;
	// m_tree.constructTreeFromPreInoder( pre_order, in_order, size);

	// Problem 4.2
	m_tree.minBST( pre_order, 7);

	// Problem 4.1
	m_tree.postOrderTraversal();
	m_tree.isBalanced();

	// Problem 4.4

	m_tree.getLevel();
	m_tree.inOrderTraversal();
	m_tree.isBST();


	m_tree.isBSTinorderTraversal();

	m_tree.testCommonAncestor();
	m_tree.findSum();

	return 0;
}