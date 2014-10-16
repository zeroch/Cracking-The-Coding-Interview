
#ifndef NODE_H
#define NODE_H 

template <typename T> 
class Node
{
public:
	Node();
	Node(T m_node);
	~Node();

	T getData();
	void setData(T);
	Node<T> * getNext();
	void setNext(Node<T> *);


private:
	T data;
	Node<T> * next;
};


#endif
