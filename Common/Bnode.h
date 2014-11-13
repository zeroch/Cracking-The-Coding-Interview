#ifndef BNODE
#define BNODE value

class Bnode
{
public:
	Bnode();
	Bnode(int);
	~Bnode();
	void setLeft(Bnode *);
	void setRight(Bnode *);
	Bnode * getLeft();
	Bnode * getRight();
	
// private:
	int data;
	Bnode * left;
	Bnode * right;
};

#endif