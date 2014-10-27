#include "Tower.h"


Tower::Tower(int size){
	tower_size = size;
	origin = new Stack(tower_size);
	buffer = new Stack(tower_size);
	dst = new Stack(tower_size);
}

Tower::~Tower(){
	// remember destory the stacks
}

Tower::Tower(Stack * m_stack){
	tower_size = m_stack->getSize();
	origin = new Stack(tower_size);
	*origin = *m_stack;
	buffer = new Stack(tower_size);
	dst = new Stack(tower_size);
}

std::ostream& operator<<(std::ostream& out, const Tower& t){

	out	<<	" Origin stack has:" 		<< 	'\n';
	out	<< 	*t.origin			<< 	'\n';
	out <<	" Buffer stack has:"		<<	'\n';
	out	<<	*t.buffer 				<<	'\n';
	out <<	" Destination stack has: "	<<	'\n';
	out <<	*t.dst 					<<	'\n';
	return out;
}


void Tower::moveDisks(int deep, Stack * origin, Stack * destination, Stack * buffer){

	if ( deep > 0)
	{
		moveDisks(deep -1, origin, buffer, destination);
		moveTop(origin, destination);
		moveDisks(deep -1, buffer, destination, origin);
	}

}


void Tower::moveTop(Stack * origin, Stack * destination){

	int top = origin->peak();
	origin->pop();
	destination->push(top);
}

void Tower::moving(){
	moveDisks(tower_size, origin, dst, buffer);
}