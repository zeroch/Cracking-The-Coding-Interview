#include "Stack.h"


Stack::Stack(int m_size){
	top_index = -1;
	size = m_size;
	stack = new int[size];
	min_stack = new int[size];
}

Stack::~Stack(){
	delete stack;
}

 std::ostream& operator<<(std::ostream& out, const Stack& s){

 	out	<<	"Top is at : "	<<	s.top_index	<< '\n';
 	out	<<	"Size is "		<<	s.size 	<< '\n';
	for (int i = s.top_index; i >= 0; --i)
	{
		out << s.stack[i]	<<	'\n';
	}
	return out;

}

int Stack::getSize(){
	return size;
}

void Stack::operator=(const Stack& s){
	if (size == s.size )
	{	
		top_index = s.top_index;
		min_index = s.min_index;
		size = s.size;
		for (int i = 0; i < size; ++i)
		{
			this->stack[i] = s.stack[i];
			this->min_stack[i] = s.min_stack[i];
		}
	}else
	{
		std::cout << "Stack size is not match, can't do a = operation"	<<	std::endl;
	}
}


void Stack::push(int m_data){
	if ( top_index > size )
	{
		std::cout << "[Stack]: the stack is full, warning to overflow"	<< std::endl;
	}else
	{
		if ( m_data < stack[top_index] )
		{
			++top_index;
			stack[top_index] = m_data;
			min_stack[top_index] = m_data;
		}else
		{
			++top_index;
			stack[top_index] = m_data;
			min_stack[top_index] = min_stack[top_index -1];
		}
	}

}


void Stack::pop(){
	if ( top_index  < 0)
	{
		std::cout << "[Stack]: the stack is empty, warning to unerflow"	<< std::endl;

	}else
	{
		--top_index;
	}
}

int Stack::peak(){
	return stack[top_index];
}

int Stack::min(){
	return min_stack[top_index];
}


bool Stack::isOverFlow(){
	if (top_index == size -1 )
		return true;
	else return false;
}

bool Stack::isUnderFlow(){
	if (top_index == -1)
		return true;
	else return false;
}


void Stack::sort(){
	Stack tmp_stack(size);
	int tmp;

	while( !this->isUnderFlow() ){
		tmp = this->peak();
		this->pop();

		while( !tmp_stack.isUnderFlow() && 
				(tmp_stack.peak() > tmp) ){
			
			this->push(tmp_stack.peak());
			tmp_stack.pop();
		}
		tmp_stack.push(tmp);
	}
	*this = tmp_stack;
}