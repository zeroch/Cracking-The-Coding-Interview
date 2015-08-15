#ifndef BTREE
#define BTREE
#include "Bnode.h"
#include <iostream>
#include <list>
#include <vector>
class BTree
{
	class Result
	{
	public:
		Result(Bnode * r_node, bool found): m_node(r_node), isAns(found){

		};

		~Result(){
		};
		
		bool isAns;
		Bnode * m_node;	
	};
public:
	BTree();
	BTree( Bnode *);
	~BTree();

	void preOrderTraversal();
	void inOrderTraversal();
	void inVisitNode(Bnode * m_root);
	void postOrderTraversal();
	void postVisitNode(Bnode * m_root);

	void constructTreeFromPreInoder(int * preOrder, int * inOrder, int size);

	Bnode *  constrHelper(int * preOrder, int * inOrder, int begin, int end, int* idx_pre);
	int searchHlper(int target, int * inOrder, int left, int right);

	bool isBalanced();
	int isBalancedHelper(Bnode * m_root);

	void minBST(int * array, int size);
	Bnode * minBSTHelper(int * array, int start, int end);

	int getLevel();
	bool isBSTHelper( Bnode * m_node, int min, int max);

	bool isBST();
	bool isBSTinorderTraversal();
	bool isBSTinorderTraversalHelper(Bnode * cur_node, int & prev);


	void testCommonAncestor();
	BTree::Result ancestorHelper(Bnode * t_node, Bnode * p, Bnode * q);
	void findSum();
	void findSumHelper(Bnode * t_node, int * path, int n, int sum);
	bool visitData(Bnode * left, Bnode * current);


private:
	Bnode * root;

};


#endif