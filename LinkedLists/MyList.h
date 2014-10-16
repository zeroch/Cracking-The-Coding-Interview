#ifndef MYLIST_H
#define MYLIST_H 
#include "Node.h"
#include <iostream>

template <class T>
class MyList
{
public:
	MyList();
	MyList(Node<T> * m_root) : head(m_root), tail(m_root){
		std::cout << "hello " << std::endl;
		std::cout << "a node is created " << std::endl;
	};

	~MyList();

	void push_back(Node<T> * m_node);
	void push_front(Node<T> * m_node);

	Node<T> * pop_back();
	Node<T> * pop_front();

	void printList();

	int removeDuplicate(MyList * m_list );
private:
	Node<T> * head;
	Node<T> * tail;
};


#endif


