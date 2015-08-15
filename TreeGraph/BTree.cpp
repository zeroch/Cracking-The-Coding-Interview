#include "BTree.h"
#include <climits>


BTree::BTree()	:	root(0) {

}

BTree::BTree(Bnode * m_root)	:	root(m_root){

}


BTree::~BTree(){

}

void BTree::inOrderTraversal(){
	if (root == 0)
	{
		std::cout << "Empty tree " 	<<	std::endl;
	}else{
		inVisitNode(root);
	}
}


// test


void BTree::inVisitNode(Bnode * m_node){
	if (m_node != 0)
	{
		inVisitNode(m_node->left);
		std::cout << "Node: " 	<<	m_node->data	<<	std::endl;
		inVisitNode(m_node->right);
	}
}


void BTree::postOrderTraversal(){
	if ( root == 0 )
	{
		std::cout << "Empty tree " 	<<	std::endl;
	}else{
		postVisitNode(root);
	}

}


void BTree::postVisitNode(Bnode * m_root){

	if ( m_root == 0)
	{
	}else{
		postVisitNode(m_root->left);
		postVisitNode(m_root->right);
		std::cout << "Node: "	<<	m_root->data	<<	std::endl;
	}
	

}

void  BTree::constructTreeFromPreInoder(int * preOrder, int * inOrder, int size){

	if ( size == 0 )
	{

	}else{
		int index_preOder = 0;
		root = constrHelper( preOrder, inOrder, 0, size -1, &index_preOder);
	}

}


Bnode *  BTree::constrHelper(int * preOrder, int * inOrder, int begin, int end, int* idx_pre){

	if (begin == end)
	{
		Bnode * root = new Bnode( preOrder[(*idx_pre)++] );
		return root;
	}else if (begin > end)
	{
		return 0;
	}

	Bnode * root = new Bnode( preOrder[(*idx_pre)++] );

	int root_index = searchHlper( root->data, inOrder, begin, end);
	root->left = this->constrHelper( preOrder, inOrder, begin, root_index -1, idx_pre);
	root->right = this->constrHelper( preOrder, inOrder, root_index +1, end, idx_pre);
	return root;
}

int BTree::searchHlper(int target, int * inOrder, int left, int right){

	for (int i = left; i <= right; ++i)
	{
		if ( inOrder[i] == target )
		{
			return i;
		}
	}
}

bool BTree::isBalanced(){

	if ( root == 0)
	{
		std::cout << "Empty tree is balanced tree" <<	std::endl;
		return true;
	}else {
		if ( isBalancedHelper(root) != -1)
		{
			std::cout << "tree is balanced tree" <<	std::endl;
			return true;
		}else {
			std::cout << " tree is not balanced tree" <<	std::endl;
			return false;
		}
	}

}

int BTree::isBalancedHelper(Bnode * m_root){

	if ( m_root == 0)
	{
		return 0;		
	}else {
			int left_height = isBalancedHelper(m_root->left);
			int right_height = isBalancedHelper(m_root->right);
			if ( left_height == -1 || right_height == -1 || left_height  != right_height	)
			{
				return -1;
			}else {
				return left_height +1;
			}
	}
}

void BTree::minBST(int * array, int size){
	if (size == 0)
	{
		std::cout << "Empty Tree" << std::endl;
	}else{
		root = minBSTHelper(array, 0, size -1);
	}
}

Bnode * BTree::minBSTHelper(int * array, int start, int end){
	if (start == end)
	{
		Bnode * m_root = new Bnode( array[start] );
	}else if (start > end)
	{
		return 0;
	}
	int mid_idx = start + ( end - start )/2;
	Bnode * m_root = new Bnode( array[mid_idx] );
	m_root->left = minBSTHelper(array, start, mid_idx -1 );
	m_root->right = minBSTHelper(array, mid_idx +1 , end);
	return m_root;
}

// return a vector of list. 
int BTree::getLevel(){

	std::vector< std::list<Bnode *>* >  m_vector;
	std::list<Bnode *> *	m_list = new std::list<Bnode *>;

	if ( root != 0)
	{
		m_list->push_back(root);
	}

	m_vector.push_back(m_list);


	std::list<Bnode *> *  m_child;

	while( m_list->size() > 0 ) {
		m_child = new std::list<Bnode *>;
		
		for (std::list<Bnode*>::iterator it = m_list->begin(); it != m_list->end(); ++it)
		{
			if ((*it)->left != 0)
				m_child->push_back((*it)->left);

			if ((*it)->right != 0)
				m_child->push_back((*it)->right);
		}

		m_vector.push_back(m_list);
		m_list = m_child;
	}

	 int level = 0;
	for (std::vector< std::list<Bnode *>* >::iterator i = m_vector.begin(); i != m_vector.end(); ++i)
	{
		 std::list<Bnode *> *  cur = *(i);
		 std::cout << "Debug: 	"	<< ++level 	<< std::endl;

		 for (std::list<Bnode *>::iterator i_list = cur->begin(); i_list != cur->end(); ++i_list)
		 {
		 	std::cout << " "	<< (*i_list)->data  << '\t';		 	
		 }

		
	}

	return level;

}

bool BTree::isBST(){

	bool result = isBSTHelper(root, INT_MIN, INT_MAX);

	std::cout << (result ? "IT is a BST"	: "IT is NOT a BST"	)	<<std::endl;
	return  result;
}



bool BTree::isBSTHelper( Bnode * m_node, int min, int max){

	if ( m_node == 0)
	{
		return true;
	}

	if ( (m_node->data < min) ||	(m_node->data > max)	)
	{
		return false;
	}

	if ( isBSTHelper(m_node->left, min, m_node->data ) && 
		 isBSTHelper(m_node->right, m_node->data, max) )
	{
		return true;
	}else {
		return false;
	}

}

bool BTree::isBSTinorderTraversal(){

	int prev = NULL;
		// std::cout << "DEBUG: current prev is " << 
		// prev 	<< std::endl; 

	bool result = isBSTinorderTraversalHelper(root, prev);
	
	std::cout << (result ? "IT is a BST"	: "IT is NOT a BST"	)	<<std::endl;
	return  result;

}

bool BTree::isBSTinorderTraversalHelper(Bnode * cur_node, int & prev){

	// traversal to check left and right. 


	if (cur_node == 0 )
	{
		return true;
	}
	if ( !isBSTinorderTraversalHelper(cur_node->left, prev)) return false;
	// std::cout << "DEBUG: current prev is " << 
	// 	prev 	<< std::endl; 
	if ( prev != NULL && cur_node-> data <= prev )
	{	
		return false;
	}
	prev = cur_node->data;

	if (! isBSTinorderTraversalHelper(cur_node->right, prev) ) return false;

	return true;
}


// void BTree::inOrderSucc(Bnode * t_node){

// 	// if already traversal the left size of t_node, but not finish the right side of t_node

// 	if ( t_node->right != 0)
// 	{
// 		Bnode * result = mostLeftNode( t_node );
// 		std::cout << "The next Node IS "	<< result->data	<<
// 		std::endl;
// 	}else{

// 	// case that t_node's parent finish the visit right side after t_node. 
// 	// next is the parent of parent
// 		Bnode * cur = t_node;
// 		Bnode * parent = cur->parent;
// 		while( parent.left != cur && parent != 0) {
// 			cur = parent;
// 			parent = cur->parent;
// 		}

// 		std::cout << "The next Node IS "	<< parent->data	<<
// 		std::endl;


// 	}

// }

// Bnode * BTree::mostLeftNode(Bnode * t_node){
// 	Bnode * cur = t_node;
// 	while( cur->left != 0) 	
// 		cur = cur->left;
// 	return cur;
// }
// // List of 

// First Commond Acestor

void BTree::testCommonAncestor(){

	Bnode * p = root->left->left;
	Bnode * q = root->right->right;

	std::cout << "[DEBUG] The p  " << p ->data
			  << " q is "	<<	q ->data 	<< std::endl;

	BTree::Result m_result = ancestorHelper(root, p, q);
	std::cout << "The common ancestor is  " << m_result.m_node->data << std::endl;

	visitData(p, root);
	visitData(q, root);


}

BTree::Result BTree::ancestorHelper(Bnode * t_node, Bnode * p, Bnode * q){

	if (t_node == NULL )
	{
		BTree::Result m_result(NULL, false);
		return m_result;
	}


		Result left = ancestorHelper(t_node->left, p, q);
		Result right = ancestorHelper(t_node->right, p, q);


		if ( left.isAns || right.isAns)
		{
			return (left.isAns ? left : right );
		}else{

			if ( left.m_node != NULL && right.m_node != NULL)
			{
				BTree::Result m_result(t_node, true);
				return m_result;

			}else if ( (left.m_node != NULL || right.m_node != NULL) 
			&& 	 (t_node == p || t_node == q) )
			{	
				BTree::Result m_result(t_node, true);
				return m_result;
			}else if ( (left.m_node == NULL && right.m_node == NULL ) )
			{

				// case no others in current side. 
				// find current is one 
				if ( (t_node == p || t_node == q)  )
				{
					BTree::Result m_result(t_node, false);
					return m_result;
				}else{
					BTree::Result m_result(NULL, false);
					return m_result;
				}
			}

		}

}

void BTree::findSum(){

	int deep = getLevel();
	int * path= new int[deep];
	findSumHelper(root, path, 0, 9);

}

void BTree::findSumHelper(Bnode * t_node, int * path, int n, int sum){
	if ( t_node != 0)
	{
		path[n] = t_node->data;
		int l_sum = 0;
		for (int i = n; i >= 0; --i)
		{
			l_sum+=path[i];
			if (sum == l_sum)
			{
				for (int j = i; j <= n; ++j)
				{
					std::cout << '\n' << 
							  "path is " 
							  << path[j] << '\t';
				}
				std::cout << '\n';
				// print the path
			}
		}
		findSumHelper( t_node->left, path, n+1, sum);
		findSumHelper( t_node->right, path, n+1, sum);
	}
}


bool BTree::visitData(Bnode * left, Bnode * current)
{
	if ( current == 0)
		return false;
	// std::cout << "Debug: " << current->data << std::endl;

	if ( current != 0 && current->data == left->data)
	{
		std::cout << "Node !: " << current->data << "\t";
		return true;
	}
	
	bool left_result = visitData(left, current->left);
	bool right_result = visitData(left, current->right);
	if ( left_result || right_result )
	{
		std::cout << "Node: " << current->data << "\t";
		return true;
	}else{
		return false;
	}
}

// bool BTree::visitData(Bnode * right, Bnode * current)
// {
// 	if ( current == 0)
// 	return false;
// 	// std::cout << "Debug: " << current->data << std::endl;

// 	if ( current != 0 && current->data == left->data)
// 	{
// 		std::cout << "Node !: " << current->data << "\t";
// 		return true;
// 	}
	
// 	bool left_result = visitData(left, current->left);
// 	bool right_result = visitData(left, current->right);
// 	if ( left_result || right_result )
// 	{
// 		std::cout << "Node: " << current->data << "\t";
// 		return true;
// 	}else{
// 		return false;
// 	}

// }


