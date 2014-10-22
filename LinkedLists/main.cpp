#include "Node.h"
#include "MyList.h"
// #include <iostream>

int main(int argc, char const *argv[])
{

	/*****

	Test Case Area

	******/



	// Node<int> * first = new Node<int>(34);
	// Node<int> * second = new Node<int>(15);
	// MyList<int>	 * m_list = new MyList<int>(first);

	// std::cout << "TEST: " << first->getData() << std::endl;

	// first->setData(50);

	// std::cout << "TEST: " << first->getData() << std::endl;

	// first->setNext(second);

	// std::cout << "TEST: second data " << first->getNext()->getData() << std::endl;


	// m_list->push_back(second);

	// Node<int> * x = new Node<int>(32);
	// Node<int> * y = new Node<int>(31);
	// Node<int> * z = new Node<int>(-15);

	// m_list->push_back(x);
	// for (int i = 0; i < 3; ++i)
	// {
	// 	x = new Node<int>(32+i);
	// 	m_list->push_back(x);
	// }

	// m_list->push_back(y);
	// m_list->push_back(z);
	// m_list->printList();



	// Problem 2.1
	// m_list->printList();
	// m_list->removeDuplicateBySet();
	// m_list->removeDuplicate();
	// m_list->printList();

	// Problem 2.2
	// m_list->printList();
	// x  = m_list->findLastKthElement( 2 );
	// m_list->printList();

	// Problem 2.3
	// m_list->printList();
	// m_list->removeNode( first );
	// m_list->printList();

	// Problem 2.4
	// m_list->printList();
	// m_list->partitionList(31);
	// m_list->printList();


	// Problem 2.5
	// Test Case A
	// reverse list. 
	// MyList<int>  operantX;
	// operantX.push_back(7);
	// operantX.push_back(1);
	// operantX.push_back(6);
	// operantX.printList();

	// MyList<int>  operantY;
	// operantY.push_back(5);
	// operantY.push_back(9);
	// operantY.push_back(2);
	// operantY.printList();

	// MyList<int> test = operantX + operantY;

	// test.printList();

	// Problem 2.6
	// circular Linked list
	// MyList<int>  m_list;
	// MyList<int>  m_list_no_circular;
	MyList<int>  m_list_empty;

	// for (int i = 0; i < 6; ++i)
	// {
	// 	m_list.push_back(i);
	// 	m_list_no_circular.push_back(i);
	// }
	// m_list.printList();

	// Node<int> * cur = m_list.getHead();

	// for (int i = 0; i < 3; ++i)
	// 	cur = cur->getNext();

	// // m_list.push_back(cur);
	// m_list.getTail()->setNext(cur);
	// std::cout << "Checking the List modify to circular : " << std::endl;
	// cur = m_list.getHead();
	// for (int i = 0; i < 7; ++i)
	// {
	// 	std::cout << "Now Node: " << cur->getData() /*<< " add_ : " << cur*/
	// 			  << std::endl;
	// 	cur = cur->getNext();

	// }

	// m_list.findCircularList();
	// m_list_empty.findCircularList();
	// m_list_no_circular.findCircularList();


	// Problem 2.7
	// Palindrome linked list. 

	MyList<int> m_list_palidrome;
	for (int i = 0; i < 4; ++i)
	{
		m_list_palidrome.push_back(i);
	}
	for (int i = 3; i >= 0; --i)
	{
		m_list_palidrome.push_back(i);
	}
	m_list_palidrome.printList();

	MyList<int> m_list_not_palidrome;
	for (int i = 0; i < 9; ++i)
	{
		m_list_not_palidrome.push_back(i);
	}
	m_list_not_palidrome.printList();

	m_list_palidrome.isPalidrome();

	m_list_not_palidrome.isPalidrome();

	return 0;
}