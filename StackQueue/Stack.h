#ifndef STACK_H
#define STACK_H
#include <iostream>

class Stack
{
public:
	Stack(int m_size);
	~Stack();

	void 	push(int m_data);
	void 	pop();
	int		findMin();
	int		min();
	int 	peak();

private:
	int size;
	int * stack;
	int * min_stack;

	int top_index;
	int min_index;
	friend std::ostream& operator<<(std::ostream& out, const Stack& s);

};

#endif // STACK_H