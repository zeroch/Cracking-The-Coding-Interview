#ifndef MQUEUE
#define MQUEUE value
#include "MyList.h"
#include "Node.h"
#include <utility>
template <class T>
class ListQueue : public MyList<T>
{
public:
	// ListQueue();
ListQueue(Node<T> * m_root): head(m_root), tail(m_root){
		// std::cout << "hello " << std::endl;
		// std::cout << "a node is created " << std::endl;
};

	// ~ListQueue();
private:
	Node<T> * head;
	Node<T> * tail;
	// MyList<T> * m_queue;
	
};

// template <class T>





#endif