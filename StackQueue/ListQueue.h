#ifndef MQUEUE
#define MQUEUE
#include "MyList.h"
#include "Node.h"
#include <utility>
template <class T>
class ListQueue : public MyList<T>
{
public:
	ListQueue() : MyList<T>(){

	};
	ListQueue(Node<T> * m_root): MyList<T>(m_root){
		// std::cout << "hello " << std::endl;
		// std::cout << "a node is created " << std::endl;
};
	~ListQueue();

	void queue(T);
	Node<T> * dequeue();
	Node<T> * peak();
	void printList();

};

template <class T>
void ListQueue<T>::queue(T m_data){

	this->push_back(m_data);

}

template <class T>
Node<T> * ListQueue<T>::dequeue(){
	return this->pop_front();
}

template <class T>
Node<T> * ListQueue<T>::peak(){
	return this->peak_front();
}

template <class T>
void ListQueue<T>::printList(){

	Node<T> * cur = this->head;
	std::cout << "[DEBUG]: Printing Queue" << std::endl;
	std::cout << "[DEBUG]: "	<< cur << std::endl;

	while(cur != 0){
		std::cout << "Now Node: " << cur->getData().second
				  << std::endl;
		cur = cur->getNext();
	}
}



#endif