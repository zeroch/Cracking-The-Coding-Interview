#include "Bnode.h"
#include <iostream>

Bnode::Bnode(){
	data = 0;
	left = 0;
	right = 0;
}

Bnode::Bnode(int m_data ): data(m_data), left(0), right(0){
	std::cout << "BNode: create "	<< data 	<<	std::endl;
}

Bnode::~Bnode(){

}


void Bnode::setLeft(Bnode * m_left){
	left = m_left;
}

void Bnode::setRight(Bnode * m_right){
	right = m_right;
}

Bnode * Bnode::getLeft(){
	return left;
}

Bnode * Bnode::getRight(){
	return right;
}
