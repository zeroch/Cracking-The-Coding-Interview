#include "AnimalShelter.h"



AnimalShelter::AnimalShelter(){

	dogQueue = new ListQueue< std::pair<int,int> >();
	catQueue = new ListQueue< std::pair<int,int> >() ;
	time_stamp = 0;

}

AnimalShelter::~AnimalShelter(){
	// remember to delete

}

void AnimalShelter::printShelter(){
	catQueue->printList();
	dogQueue->printList();
} 

// m_type : fix it use enum. 
void AnimalShelter::enqueue(animalType m_type, int m_ID){

	std::pair<int,int> m_animal(++time_stamp, m_ID);

	switch ( m_type ){
		case CAT :
			catQueue->queue( m_animal );
			break;
		case DOG :
			dogQueue->queue( m_animal );
			break;
		default	:
			break;
	}
}

// cat is older return 1, 
bool AnimalShelter::pickQueue(){
	std::pair<int, int> m_cat = catQueue->peak()->getData();
	std::pair<int, int> m_dog = dogQueue->peak()->getData();

	if ( m_cat.first < m_dog.first)
		return true;
	else return false;
}

int AnimalShelter::dequeueCat(){

	Node< std::pair<int, int>> * m_node = catQueue->dequeue();
	std::pair<int, int> m_cat = m_node->getData();
	int m_ID = m_cat.second;
	return m_ID;

}
int AnimalShelter::dequeueDog(){

	Node< std::pair<int, int>> * m_node = dogQueue->dequeue();
	std::pair<int, int> m_dog = m_node->getData();
	int m_ID = m_dog.second;
	return m_ID;

}

int AnimalShelter::dequeueAny(){
	bool from_catQueue = this->pickQueue();
	if ( from_catQueue )
		return this->dequeueCat();
	else return this->dequeueDog();
}
