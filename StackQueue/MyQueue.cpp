#include "MyQueue.h"

MyQueue::MyQueue(int m_size){
	size = m_size;
	top_index = -1;
	m_queue = new Stack(size);
	m_buffer = new Stack(size);

}

MyQueue::~MyQueue(){
	// TODO remember to delete the stacks
}

std::ostream& operator<<(std::ostream& out, const MyQueue& q){

	out << "The content in the m_queue is : "	<<	'\n';
	out <<	*q.m_queue		<<		'\n';
	out	<<	"The content in the m_buffer is:	" << '\n';
	out	<<	*q.m_buffer 		<<		'\n';
	return out;
}


void MyQueue::queue(int m_data){
	if ( !m_queue->isOverFlow() )
	{
		m_queue->push(m_data);
	}else
	{
		std::cout <<	"Warning: m_queue is full, it will cause overflow"	<<	std::endl;
	}
}

int MyQueue::dequeue(){
	// push all data to m_buffer, data is reversed in the m_buffer, so we can easily pop the first one. 

	while( !m_queue->isUnderFlow() ){
		m_buffer->push(m_queue->peak());
		m_queue->pop();
	}
	int result = m_buffer->peak();
	m_buffer->pop();
	while( !m_buffer->isUnderFlow() ){
		m_queue->push(m_buffer->peak());
		m_buffer->pop();
	}

	return result;

}