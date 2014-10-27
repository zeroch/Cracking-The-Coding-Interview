#ifndef MYQUEUE
#define MYQUEUE
#include "Stack.h"
#include <iostream>
// this is queue implemented by two stacks
class MyQueue
{
public:
	MyQueue(int);
	~MyQueue();
	void queue(int);
	int dequeue();

private:
	Stack * m_queue;
	Stack * m_buffer;
	int size;
	int top_index;
	friend std::ostream& operator<<(std::ostream& out, const MyQueue& q);
};



#endif
