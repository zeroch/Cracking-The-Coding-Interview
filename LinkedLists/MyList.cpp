// #include <iostream>
#include "MyList.h"

template<class T>
MyList<T>::MyList(){
	head = 0;
	tail = 0;
}

template <class T>
MyList<T>::~MyList(){

}

template <class T>
void MyList<T>::push_back(Node<T> * m_node){
	if (head == 0 && tail == 0)
	{
		head = m_node;
		tail = m_node;
	}else{

		tail->setNext(m_node);
		tail = m_node;
	}
}

template <class T>
void MyList<T>::push_front(Node<T> * m_node){
	if (head == 0 && tail == 0)
	{
		head = m_node;
		tail = m_node;
	}else {
		m_node->setNext(head);
		head = m_node;
	}
}

template <class T>
Node<T> * MyList<T>::pop_back(){
	if (head == 0 && tail == 0)
	{
		std::cout << "Empty List" << std::endl;
		return 0;
	}else 
	{

		Node<T> * slow = head;
		Node<T> * fast = slow->getNext();

		while(fast != tail){
			fast = fast->getNext();
			slow = slow->getNext();
		}

		// pop so the tail is going to delete out side the function. 
		tail = slow;
		return fast;
	}
}

template <class T>
Node<T> * MyList<T>::pop_front(){
	if ( head == 0 && tail == 0)
	{
		std::cout << "Empty List" << std::endl;
		return 0;
	}else
	{
		Node<T> * result = head;
		head = head->getNext();
		return result;
	}
}

template <class T>
void MyList<T>::printList(){

	Node<T> cur = head;

	while(cur != 0){
		std::cout << "Now Node: " << cur->getData()
				  << std::endl;
		cur = cur->getNext();
	}
}