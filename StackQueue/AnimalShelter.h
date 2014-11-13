#ifndef ANIMALSHELTER
#define ANIMALSHELTER
#include "ListQueue.h"
#include <utility>

class AnimalShelter
{
public:
	AnimalShelter();
	~AnimalShelter();

	enum animalType	{	CAT, DOG };

	void enqueue(animalType type, int m_ID);
	int dequeueAny();
	int dequeueDog();
	int dequeueCat();
	bool pickQueue();
	void printShelter();

private:

	ListQueue< std::pair<int,int> > * dogQueue;
	ListQueue< std::pair<int,int> > * catQueue;
	int time_stamp;

};
#endif