// SetofStack
#include "Node.h"
#include "Stack.h"


class SetOfStack
{
public:
	SetOfStack();
	~SetOfStack();

	void push( int );
	void pop();
	int peak();

private:
	Node<Stack *> * top;
	Stack * current_Stack;

	friend std::ostream& operator<<(std::ostream& out, const SetOfStack& s);


};