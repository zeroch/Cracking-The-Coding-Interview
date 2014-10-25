// Test file for the Stack and Queue part
#include <iostream>
#include "Stack.h"
#include "SetOfStack.h"
int main(int argc, char const *argv[])
{
	// Problem 3.2
	// O(1)  push, pop and findMin
	Stack m_stack(100);
	std::cout	<<	m_stack			<< std::endl;
	m_stack.push( -9 );
	for (int i = 0; i < 23; ++i)
	{
		m_stack.push(i);
	}
	m_stack.pop();

	Stack * copy_stack = new Stack(100);
	Stack copy_stack_false(12);

	// std::cout	<<	m_stack.peak()	<<	std::endl;
	std::cout	<<	m_stack			<< std::endl;
	// std::cout	<<	m_stack.min()	<< std::endl;

	std::cout	<<	copy_stack			<< std::endl;

	*copy_stack = m_stack;
	std::cout	<<	*copy_stack			<< std::endl;

	copy_stack_false = m_stack;
	std::cout	<<	copy_stack_false		<< std::endl;


	// Problem 3.3
	// Set of Stack 

	// SetOfStack m_stack;

	// for (int i = 0; i < 90; ++i)
	// {
	// 	m_stack.push(i);
	// }

	// std::cout << m_stack <<	std::endl;



	return 0;
}