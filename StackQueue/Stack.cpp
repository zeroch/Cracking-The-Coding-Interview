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
		out << s.stack[i]	<<	" Min" 	<< 	s.min_stack[i]	<<	'\n';
	}
	return out;

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