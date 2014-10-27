// Test file for the Stack and Queue part
#include <iostream>
#include <utility>
#include "Stack.h"
#include "SetOfStack.h"
#include "Tower.h"
#include "MyQueue.h"
#include "ListQueue.h"
#include "Node.h"

int main(int argc, char const *argv[])
{
	// Problem 3.2
	// O(1)  push, pop and findMin
	// Stack m_stack(100);
	// std::cout	<<	m_stack			<< std::endl;
	// m_stack.push( -9 );
	// for (int i = 0; i < 23; ++i)
	// {
	// 	m_stack.push(i);
	// }
	// m_stack.pop();

	// Stack * copy_stack = new Stack(100);
	// Stack copy_stack_false(12);

	// // std::cout	<<	m_stack.peak()	<<	std::endl;
	// std::cout	<<	m_stack			<< std::endl;
	// // std::cout	<<	m_stack.min()	<< std::endl;

	// std::cout	<<	copy_stack			<< std::endl;

	// *copy_stack = m_stack;
	// std::cout	<<	*copy_stack			<< std::endl;

	// copy_stack_false = m_stack;
	// std::cout	<<	copy_stack_false		<< std::endl;


	// Problem 3.3
	// Set of Stack 

	// SetOfStack m_stack;

	// for (int i = 0; i < 90; ++i)
	// {
	// 	m_stack.push(i);
	// }

	// std::cout << m_stack <<	std::endl;


	// Problem 3.4
	// 
	// Stack m_stack(5);
	// for (int i = 1; i < 6; ++i)
	// {
	// 	m_stack.push(i);
	// }
	// Tower m_tower(&m_stack);
	// std::cout << m_tower	<<	std::endl;
	// m_tower.moving();
	// std::cout << m_tower	<<	std::endl;

	// Problem 3.5
	// use two stacks to implement queue

	// MyQueue m_queue(10);
	// for (int i = 0; i < 12; ++i)
	// {
	// 	m_queue.queue(i);
	// }

	// std::cout << m_queue	<< std::endl;
	// for (int i = 0; i < 12; ++i)
	// {
	// 	m_queue.dequeue();
	// }
	// std::cout << m_queue	<< std::endl;


	// Problem 3.5
	// Stack m_stack(5);
	// m_stack.push(5);
	// m_stack.push(-5);
	// m_stack.push(45);
	// m_stack.push(8);
	// m_stack.push(15);

	// std::cout << m_stack	<< std::endl;

	// m_stack.sort();

	// std::cout << m_stack	<< std::endl;
	

	// Problem 3.6


	std::pair<int,int> m_cat(1, 5);
	std::cout << m_cat.first	<< '\t'	<<	m_cat.second	<<	std::endl;

	Node<std::pair<int,int> > * m_node = new Node< std::pair<int,int>  >(m_cat);

	Node<std::pair<int,int>> * x = new Node<std::pair<int,int>>(m_cat);

	ListQueue< std::pair<int,int> > * m_list = new ListQueue<std::pair<int,int> >(x);

	Node< std::pair<int, int> > * cat = m_list->pop_back();

	// std::cout << cat->getData().first	<< '\t'	<<	cat->getData().second	<<	std::endl;

	// MyList< <std::pair<int,int> >  * m_catlist = new MyList< std::pair<int,int>>(m_node);


	return 0;
}