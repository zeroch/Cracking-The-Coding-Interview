#ifndef TOWER_H
#define TOWER_H

#include "Stack.h"

class Tower
{
public:
	// Tower();
	Tower(int);
	Tower(Stack * m_stack);
	~Tower();

	Stack * getOrigin() { return origin;		};
	Stack * getBuffer() { return buffer;	};
	Stack * getDst() 	{ return dst;		};

	void moveDisks(int deep, Stack * origin, Stack * destination, Stack * buffer);

	void moveTop(Stack * origin, Stack * destination);
	void moving();	
private:
	Stack * origin;
	Stack * buffer;
	Stack * dst;
	int tower_size;
	friend std::ostream& operator<<(std::ostream& out, const Tower& t);

};

#endif

