#ifndef NODE_CPP
#define NODE_CPP 
#include "Node.h"
#include <iostream>

template <typename T> 
Node<T>::Node(){ 
	next = 0;
}

template <typename T> 
Node<T>::Node(T m_node){

		data = m_node;
		next = 0;
		std::cout << "hello " << std::endl;
		std::cout << "a node is created " << 
							data 		<<   std::endl;


} 

template <typename T> 
Node<T>::~Node(){

}

template <typename T> 
T Node<T>::getData(){
	return this->data;
}

template <typename T> 
void Node<T>::setData(T m_node){
	data = m_node;
}

template <typename T>
Node<T> * Node<T>::getNext(){
	return next;
}

template <typename T> 
void Node<T>::setNext(Node<T> * m_node){
	next = m_node;
}



#endif
