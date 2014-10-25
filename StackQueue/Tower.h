#ifndef TOWER_H
#define TOWER_H
#include "Stack.h"


class Tower
{
public:
	Tower();
	Tower(int);
	Tower(Stack * m_stack){
	~Tower();
	
private:
	Stack * orgin;
	Stack * buffer;
	Stack * dst;
	int tower_size;
	friend std::ostream operator<<(std::ostream out, const Tower& t);

};



#endif

