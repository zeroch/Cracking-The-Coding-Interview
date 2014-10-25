#include "SetOfStack.h"

SetOfStack::SetOfStack(){

	// assume each stack only have size 8
	current_Stack = new Stack(8);
	top = new Node<Stack *>(current_Stack);
}

SetOfStack::~SetOfStack(){
	// TODO: remember to destory everything. 
}

void SetOfStack::push(int m_data){

	if ( current_Stack->isOverFlow() )
	{
		// create new stack and update the list
		// then push the data in there. 

		Stack * tmp_stack = new Stack(8);
		Node<Stack *>  * tmp_node = new Node<Stack *>(tmp_stack);
		tmp_node->setNext(top);
		top = tmp_node;
		current_Stack = tmp_stack;

	}

		current_Stack->push(m_data);
}

void SetOfStack::pop(){

	if ( current_Stack->isUnderFlow() )
	{
		// current stack is underflow, switch the next stack 
		// destory the Stack and it's container.. 

		// check if this is the last Stack in the set. Don't destory. 
		if ( top->getNext() == 0 )
		{
			std::cout << "The stack is empty, Nothing to pop out "	<< std::endl;
		}else
		{
			delete current_Stack;
			current_Stack = 0;
			delete top;
			top = 0;

			// already checked the top is save to access. 
			top = top->getNext();
			current_Stack = top->getData();
		}

	}

	current_Stack->pop();

}

int SetOfStack::peak(){
	return current_Stack->peak();
}


std::ostream& operator<<(std::ostream& out, const SetOfStack& s){

	Node<Stack *> * tmp_node = s.top;

	while( tmp_node != 0 ) {

		out << *(tmp_node->getData()) ;
		tmp_node = tmp_node->getNext();
	}

	return out ;


}
