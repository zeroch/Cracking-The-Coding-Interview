#include "Tower.h"


Tower::Tower(int size){
	tower_size = size;
	orgin = new Stack(tower_size);
	buffer = new Stack(tower_size);
	dst = new Stack(tower_size);
}

Tower::~Tower(){
	// remember destory the stacks
}

Tower::Tower(Stack * m_stack){
	tower_size = m_size->size();
	orgin = new Stack(tower_size);
	orgin = &m_stack;
	buffer = new Stack(tower_size);
	dst = new Stack(tower_size);
}