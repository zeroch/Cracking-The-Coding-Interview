#ifndef NODE_H
#define NODE_H 
#include <iostream>

template <class T> 
class Node
{
public:

	Node();
	Node(T m_node);
	~Node();

	T getData();
	void setData(T);
	Node<T> * getNext();
	void setNext(Node<T> *);
	void operator=(const Node<T>& n); 


private:
	T data;
	Node<T> * next;
};


template <class T> 
Node<T>::Node(){ 
	next = 0;
}

template <class T> 
Node<T>::Node(T m_node){

		data = m_node;
		next = 0;
} 

template <class T> 
Node<T>::~Node(){

}

template <class T>
void Node<T>::operator=(const Node& n){
	data = n.data;
	next = n.next;
}


template <class T> 
T Node<T>::getData(){
	return this->data;
}

template <class T> 
void Node<T>::setData(T m_node){
	data = m_node;
}

template <class T>
Node<T> * Node<T>::getNext(){
	return next;
}

template <class T> 
void Node<T>::setNext(Node<T> * m_node){
	next = m_node;
}


#endif
